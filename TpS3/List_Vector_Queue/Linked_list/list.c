# include <stdlib.h>
# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "list.h"


void list_init(struct list *list)
{
   list = malloc (sizeof (struct list));
   list->data=0;
   list->next =NULL;
}
int list_is_empty(struct list *list)
{
  if (list->next != NULL)
      return 0;
  else
      return 1;
}
size_t list_len(struct list *list)
{
  size_t len =0;
  for (;list->next!=NULL ; list = list->next)
  {
    len++;
  }
  return len;
}
void push_front (struct list *list, int x)
{
  list =list->next;
  list=x;
}
void list_push_front(struct list *list, struct list *elm)
{
  elm->next=list->next;
  list->next = elm;
}
struct list* list_pop_front(struct list *list)
{
  /*if (list_is_empty(list))
    return NULL;
  else
  {
    struct list *stocklist = malloc ((sizeof(struct list))-1);
    list_init(stocklist);
    //list->data=NULL;
    stocklist = list->next;
    //stocklist->data = list->data;
    //list =list->next;
    return stocklist;*/
    if (list_is_empty(list))
      return NULL;

  struct list *pop = list->next;
  list->next = pop->next;
  return pop;
}
struct list* list_find(struct list *list, int value)
{
 if (list_is_empty(list->next))
    return NULL;
 else
 {
   for (;list->next != NULL; list =list->next)
   {
     if (list->next->data == value)
       return list;
   }
 }
 return NULL;
}
struct list* list_lower_bound(struct list *list, int value)
{
  if (list_is_empty(list))
  {
    return NULL;
  }
  else
  {
    struct list *list2;
    for (; list->next->next !=NULL ; list=list->next)
    {
      list2=list;
      if ( list->next->next->data > value)
         return list2;
    }
    return NULL;
  }
}
int list_is_sorted(struct list *list)
{
if (list_is_empty(list) || list_len(list)<2)
{
  return 1;
}
if (list_len(list)<2)
{
  return 1;
}
size_t len = list_len(list);
size_t i =0;
list=list->next;
while((list->next!=NULL)&&(list->next->data >= list->data))
{
 i++;
 list=list->next;
}
return (i==len-1);
}
// NULL -> 3 -> 19 -> 11
void list_insert(struct list *list, struct list *elm)
{
 list_push_front(list,elm);
 for (;list->next->next!=NULL;list=list->next)
 {
   if (list->next->data>list->next->next->data)
   {
     int temp = list->next->data;
     list->next->data =list->next->next->data;
     list->next->next->data = temp;
   }
 }
}
void list_rev(struct list *list)
{
  struct list *tmp = malloc (sizeof(struct list));
list_init(tmp);
struct list *tmp2 = list;
while(tmp2->next != NULL){
  list_push_front(tmp, list_pop_front(list));
}
list->next = tmp->next;
}
void list_half_split(struct list *list, struct list *second)
{
    int i = list_len(list) / 2;
    struct list *temp = list;
    while(i > 0)
    {
      temp = temp->next;
      i -=1;
    }
    second->next = temp->next;
    temp->next = NULL;
}
/*void list_insert_sort(struct list *list)
{
  if (list_is_empty(list))       // nothing to do
    return;
  struct list fake_head = {0,0}; // temporary head
  while (!list_is_empty(list)) {
    struct list *elm = list_pop_front(list);
    list_insert(&fake_head, elm);
  }
  list->next = fake_head.next;   // reattach the sorted list to its sentinel
}*/
void print_list(struct list *list)
{
  int line = printf("[");
  if (list->next) {
    goto pastfst;
    while (list->next) {
      line += printf(";");
      if (line > 72) {
	printf("\n ");
	line = 1;
      }
      pastfst:
      line += printf(" %d", list->next->data);
      list = list->next;
    }
  }
  printf(" ]\n");
}
 int main (void)
 {
  struct list a;
  struct list b;
  struct list c;
  struct list d;
  struct list e;
  list_init(&a);
  list_init(&b);
  list_init(&c);
  list_init(&d);
  list_init(&e);
  a.next = &b;
  b.next = &c;
  b.data = 10;
  c.data = 20;
  d.data = 10;
  e.data = 15;
  printf("=====Push_Front====\n");
  print_list(&a);
//  list_push_front(&a,list_pop_front(&a));
  //print_list(&a);
  list_push_front(&a,&d);
  print_list(&a);
  printf("=====Pop_Front====\n");
  print_list(&a);
  print_list(list_pop_front(&a));
  printf("=====List_Find====\n");
  print_list(&a);
  print_list(list_find(&a,10));
  printf("=====List_Lower_Bound====\n");
  print_list(&a);
  print_list(list_lower_bound(&a,9));
  printf("=====IsSorted=====\n");
  print_list(&a);
  printf("Is Sorted :%d\n",list_is_sorted(&a));
  printf("=====Insert=====\n");
  print_list(&a);
  list_insert(&a,&e);
  print_list(&a);
  printf("====Reverse====\n");
  print_list(&a);
  list_rev(&a);
  print_list(&a);
  return 0;
 }
