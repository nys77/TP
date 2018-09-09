# include <stdlib.h>
# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "vector.h"



// returns false if something goes wrong (realloc fails)
int double_vector_size(struct vector *vect)
{
  int *tmp = realloc(vect->data, 2 * vect->capacity * sizeof (int));
  if (tmp == NULL) {
    // oups no more memory ?
    warn("realloc of data fails");
    return 0;
  }
  vect->data = tmp;
  vect->capacity *= 2;
  return 1;
}

int vector_init(struct vector *vect, size_t capacity)
{
    vect = malloc(sizeof(vect));
    vect->data = malloc(capacity * (sizeof(int)));
    vect->capacity = capacity;
    vect->size = 0;
}
struct vector* vector_make(size_t capacity)
{
     struct vector *vect = malloc(sizeof(vect));
     vect->data = malloc(capacity * (sizeof(int)));
     vect->capacity = capacity;
     vect->size = 0;
     return vect;
}
void vector_push_back(struct vector *vect, int x)
{
  if (vect->size==vect->capacity)
    double_vector_size(vect);
  vect->data[vect->size] = x;
  vect->size+=1;
}

int  vector_pop_back(struct vector *vect, int *x)
{
  if (vect->size > 0)
  {
    for (int i =0 ; i<vect->size;i++)
    {
      if (i==0)
      {
        x=vect->data[i];
        vect->size--;
      }
    }
  }
  return (vect->size >0);
}
int vector_push_front(struct vector *vect, int x)
{
  if (vect->size==vect->capacity)
    double_vector_size(vect);
  int temp;
  for (int i =0; i < vect->size ; i++)
  {
    if (i==0)
    {
      temp = vect->data[i];
      vect->data[i] = x;
      vect->size+=1;
    }
    else
    {
      int save =vect->data[i];
      vect->data[i]=temp;
      temp =save;
    }
  }
}
int  vector_pop_front(struct vector *vect, int *x)
{

 if (vect->size > 0)
 {
   int temp;
   for (int i =0 ; i < vect->size ;i++)
   {
       int save =vect->data[i];
       vect->data[i]=vect->data[i+1];
       vect->data[i+1]=temp;
   }
   vect->size-=1;
 }
 return (vect->size >0);
}
int vector_insert_at(struct vector *vect, size_t pos, int x)
{
  int b=1;
  if (vect->size==vect->capacity)
    double_vector_size(vect);
  if (pos ==0 && b)
  {
    vector_push_front(vect,x);
    b=0;
  }
  else if (pos==vect->size-1 && b)
  {
    vector_push_back(vect,x);
    b=0;
  }
  vector_push_front(vect,x);
  int i=0;
  while (pos > i && i<vect->size)
  {
    int save =vect->data[i];
    vect->data[i]=vect->data[i+1];
    vect->data[i+1]=save;
    i++;
    pos--;
  }
  vect->data[i]=x;
}
int vector_extract_at(struct vector *vect, size_t pos, int *x)
{
  if (pos ==0)
  {
    x=vect->data[0];
    vector_pop_front(vect,&x);
    return x;
  }
  else if (pos==(vect->size)-1)
  {
    x= vect->data[vect->size];
    vector_pop_back(vect,&x);
    return x;
  }
  size_t i =0;
  for (;i<pos;i++)
  {

  }
  x=vect->data[i];
  for (;i<vect->size;i++)
  {
    int save =vect->data[i];
    vect->data[i]=vect->data[i+1];
    vect->data[i+1]=save;
  }
  vector_pop_back(vect,0);
  return x;
}
struct vector* vector_clone(struct vector *vect)
{
  struct vector *vect1 = vector_make(vect->capacity);
  for (int i =0;i<vect->size;i++)
  {
    vector_push_back(vect1,vect->data[i]);
  }
  return vect1;
}
void print_vect (struct vector *vect)
{
  printf("[");
  for (size_t i =0;i < vect->size;i++)
  {
    if (i == (vect->size)-1)
      printf(" %d",vect->data[i]);
    else
      printf(" %d ;",vect->data[i]);
  }
  printf(" ]\n");
}
int main (void)
{
    struct vector *vect;
    vect = vector_make(0);
    vector_push_back(vect,2);
    printf("====Push_Back====\n");
    print_vect(vect);
    int x =3;
    vector_push_back(vect,x);
    printf("After push back  %d -> ",x);
    print_vect(vect);
    printf("====Pop_Back====\n");
    print_vect(vect);
    int c = vector_pop_back(vect,0);
    printf("After pop back   -> ");
    print_vect(vect);
    printf("====Push_front====\n");
    int a =0;
    print_vect(vect);
    int b =vector_push_front(vect,a);
    printf("After push front  %d -> ",a);
    print_vect(vect);
    printf("====Pop_Front====\n");
    print_vect(vect);
    printf("After pop front -> ");
    vector_pop_front(vect,10);
    print_vect(vect);
    printf("====Vect_Insert====\n");
    print_vect(vect);
    int z =20;
    printf("After Insert %d -> ",z);
    vector_insert_at(vect,2,9);
    print_vect(vect);
    printf("====Extract_at====\n");
    vector_push_back(vect,10);
    vector_push_back(vect,20);
    vector_push_back(vect,30);
    print_vect(vect);
    vector_extract_at(vect,1,x);
    print_vect(vect);
    printf("====Copy====\n");
    print_vect(vect);
    struct vector *vect1= vector_clone(vect);    
    print_vect(vect1);
    return 0;
}
