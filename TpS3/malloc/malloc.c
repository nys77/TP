
# define _XOPEN_SOURCE 500
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h> 
# include <string.h>
# include <errno.h>
# include <time.h>

struct chunk {
  struct chunk *next, *prev;
  size_t        size;
  long          free;
  void         *data;
};

/*static inline size_t word_align(size_t n)
{
	size_t s = sizeof(size_t);
	if (s&n)
	{
		return n;
	}
	return s + n - (s&n);
}*/ //Old version

static inline size_t word_align(size_t n)
{
	return (n + (sizeof(size_t) -1)) & (~(sizeof(size_t)-1));
}
 //zerofill(ptr, len): write len 0 bytes at the address ptr
static
void zerofill(void *ptr, size_t len)
{   

    for (size_t i = 0; i < (len/sizeof(size_t)); i++)
    {
        ((size_t*)ptr)[i] = 0;
    }
}


/* wordcpy(dst, src, len) copy len bytes from src to dst */
static
void wordcpy(void *dst, void *src, size_t len)
{
    for (size_t i = 0; i < (len/sizeof(size_t)); i++)
    {
        ((size_t*)dst)[i] = ((size_t*)src)[i];
    }
}

static
struct chunk* get_base(void) {
  
  static struct chunk *base = NULL;
  if (base == NULL) {

  	base = sbrk(sizeof (struct chunk));
	if (base != (void*)(-1))
	{
		base->prev = NULL;
		base->next = NULL;
		base->free = 0;
		base->size = 0;
		base->data = NULL;
	}
	else
		_exit(71);
  }
  return base;
}

/*
 * extend_heap(last, size) extends the heap with a new chunk containing a data block of size bytes.
 * Return 1 in case of success, and return 0 if sbrk(2) fails.
 */
static
int extend_heap(struct chunk *last, size_t size)
{	
		struct chunk *new = sbrk(size + sizeof(struct chunk));
		if (new != (void*)(-1))
		{
			last->next = new;
			new->next = NULL;
			new->prev = last;
			new->size = size;
			new->free = 1;
			new->data = (void*)new + word_align(sizeof(struct chunk));
			return 1;
		}
		return 0;
		_exit(71);
}

static
struct chunk* find_chunk(size_t size)
{
	struct chunk *base = get_base();
	while (base->next && !(base->next->free && base->next->size >= size))
	{
		base = base->next; 
	}
	return base;
}



static struct chunk *get_chunk(void *p) {
	void *sbreak = sbrk(0);
	void *base = get_base();

	if (p && word_align(((size_t)p)) == ((size_t)p) && p >= base && p <= sbreak)
	{
		struct chunk *c = (struct chunk*)(p - word_align(sizeof(struct chunk)));
		if (p != c->data)
			return NULL;
		return c;
	}
	return NULL;
}

static struct chunk* merge_chunk(struct chunk *p)
{
	struct chunk *side = p->next;
	if (side && side->free)
	{
		p->next = side->next;
		if (side->next)
			side->next->prev = p;
		p->size += side->size + word_align(sizeof(struct chunk));
	}
	side = p->prev;
	if (side && side->free)
		merge_chunk(side);
	return side;
}

static void split_chunk(struct chunk *p, size_t size)
{
	if (p->size > size + word_align(sizeof(struct chunk)))
	{
		struct chunk *next = p->next;
		struct chunk *new_chunk = (struct chunk*)((void*)p + word_align(sizeof(struct chunk)) + size);
		new_chunk->prev = p;
		new_chunk->next = next;
		p->next = new_chunk;
		if (next)
			next->prev = new_chunk;
		new_chunk->free = 1;
		new_chunk->size = p->size - size - word_align(sizeof(struct chunk));
		new_chunk->data = (void*)new_chunk + word_align(sizeof(struct chunk));

	}
}

void *malloc(size_t size)
{ 
	size_t align = word_align(size);
	struct chunk *p = find_chunk(align);
	if (!size)
	{
		return NULL;
	}
	if (!(p->next) && !extend_heap(p, align))
		return NULL;
	split_chunk(p->next, align);
	p = p->next;
	p->size = align;
	p->free = 0;
	return p->data;
}

void *calloc(size_t nb, size_t size)
{
	void *data = malloc(nb * size);
	if (data)
		zerofill(data, word_align(nb * size));
	return data;
}

void* realloc(void *old, size_t newsize)
{
	struct chunk *chunk = get_chunk(old);
	if (!chunk)
		return malloc(newsize);
	if (!newsize)
	{
		chunk -> free = 1;
		return NULL;
	}
	if (chunk -> size >= newsize)
		return old;
	void *reallocated = malloc(newsize);
	if (!reallocated)
		return NULL;
	size_t smallest_size = chunk->size < newsize ? chunk -> size : newsize;
	wordcpy(reallocated, old, smallest_size);
	chunk->free = 1;
	return reallocated;
}

static void back_memory(struct chunk *p)
{
	if (!p->next && p->prev && p->prev->next)
	{
		p->prev->next = NULL;
		brk(p);
	}
}

void free(void *p)
{
	struct chunk *c = get_chunk(p);
	if (c)
	{
		c->free = 1;
		merge_chunk(c);
		back_memory(c);
	}
}
