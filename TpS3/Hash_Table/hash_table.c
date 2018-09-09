# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <err.h>
# include "hash_table.h"


uint32_t hash(char *data)
{
  uint32_t h = 0;
  for(; *data != '\0'; ++data){
          h += *data;
          h += h*1024;
          h = h^(h/64);
  }
  h += h*8;
  h = h^(h/2048);
  h += h*32768;
  return h;

}
struct htable *create_htable(size_t capacity)
{
        struct htable *tab = malloc (sizeof(struct htable));
        tab->size = 0;
        tab->capacity = capacity;
        tab->tab = malloc (capacity*sizeof(struct pair));
        return tab;
}
struct pair *access_htable(struct htable *htable, char *key)
{
    if (htable->size == 0)
            return NULL;
    uint32_t k = hash(key);
    size_t index = k%(htable->capacity);
    struct pair *list = htable->tab[index];
    for(; list && k != list->hkey && strcmp(key, list->key); list = list->next){
            continue;
    }
    return list;
}
int add_htable(struct htable *htable, char *key, void *value)
{
  struct pair *val = access_htable(htable, key);
         if (val != NULL)
         {
                 return 0;
         }
         uint32_t h = hash(key);
         size_t index  = h %(htable->capacity);
         htable->size = htable->size+1;
         if((htable->size)/(htable->capacity)>0.75)
         {
                 struct htable *htable_bis = create_htable((htable->capacity)*2);
                 for(size_t i = 0; i < (htable->capacity); ++i)
                 {
                         while(htable->tab[i] != NULL)
                         {
                                 uint32_t h_bis  = hash(htable->tab[i]->key);
                                 size_t index_bis = h_bis % ((htable->capacity)*2);
                                 struct pair *pair_bis = malloc(sizeof(struct pair));
                                 pair_bis->hkey = h_bis;
                                 pair_bis->key = htable->tab[i]->key;
                                 pair_bis->value = htable->tab[i]->value;
                                 pair_bis->next = htable_bis->tab[index_bis];
                                 htable_bis->tab[index_bis] = pair_bis;
                                 htable->tab[i] = htable->tab[i]->next;
                         }
                 }
                 size_t index_bis = h%((htable->capacity)*2);
                 struct pair *pair_bis = malloc(sizeof(struct pair));
                 pair_bis-> hkey = h;
                 pair_bis-> key = key;
                 pair_bis->value = value;                                               pair_bis->next = htable_bis->tab[index_bis];
                 htable_bis->tab[index_bis] = pair_bis;
                 struct htable *htable2nd = malloc(sizeof(struct htable));
                 htable2nd->tab = htable->tab;

                 htable->tab = htable_bis->tab;
                 htable_bis->tab = htable2nd->tab;
                 htable->capacity = htable->capacity*2;
                 clear_htable(htable_bis);
                 free(htable2nd);
         }
         else
         {
                 struct pair *pair = malloc(sizeof(struct pair));
                 pair->hkey = h;
                 pair->key = key;
                 pair->value = value;
                 pair->next = htable->tab[index];
                 htable->tab[index] = pair;
         }
         return 1;
}
void remove_htable(struct htable *htable, char *key)
{
  struct pair *tmp = access_htable(htable, key);
      if (tmp){
              size_t i = (tmp->hkey)%(htable->capacity);
              if (htable->tab[i]->key != key){
                      for(; htable->tab[i]->next->key != key; htable->tab[i] = htable->tab[i]->next){
                              continue;
                      }
                      htable->tab[i]->next = htable->tab[i]->next->next;
              }
              else{
                      htable->tab[i] = htable->tab[i]->next;
              }
              --htable->size;
      }
}
void clear_htable(struct htable *htable)
{
  for(size_t k = 0; k < htable->capacity; ++k){
                 htable->tab[k] = NULL;
 	}
         htable->size = 0;
}
int main(void)
{
  return 0;
}
