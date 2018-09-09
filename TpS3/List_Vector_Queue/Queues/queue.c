# include "queue.h"
# include <stdio.h>
# include <stdlib.h>

void queue_init(struct queue *queue)
{
  queue->store = NULL;
  queue->size = 0;
}
int queue_is_empty(struct queue *queue)
{
  return queue->size==0;
}

void queue_push(struct queue *queue, void *elm)
{
  queue->size+=1;
  while (queue->store->next != NULL)
      queue->store = queue->store->next;
    queue->store->next = elm;
}

void* queue_pop(struct queue *queue)
{
  if (queue_is_empty(queue))
  {
    return NULL;
  }
  struct list *pop = queue->store->next;
  queue->store->next = pop->next;
  queue->size-=1;
  return pop;
}
void print_Queue(struct queue *queue)
{
  printf("[");
  for (;queue->store->next !=NULL ; queue->store=queue->store->next)
  {
    printf (" %d ;", queue->store->next);
  }
  printf("[\n");
}
int main(void)
{
  struct queue queue;
  queue_init(&queue);
  queue_push(&queue,malloc(1));
  queue_pop(&queue);
  return 0;
}
