/* helper's functions */

# define _XOPEN_SOURCE 500

# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "helper.h"

/* swap(a,b): swap memory location content */
void swap(int *a, int *b)
{
  int temp = *a;
  *a=*b;
  *b=temp;
}
int sum_of_divisors(int x, size_t *count)
{
  int somme =0;
  *count=0;
  for (int i =1; i <= x ; i++)
  {
    if ((x%i)==0)
    {
      somme += i;
      *count+=1;
    }
  }
  return somme;
}
/* array_print(begin, end) print integer array */
/* with a fixed padding of 4 chars             */
void array_print(int *begin, int *end)
{
  int line = 0;
  for (; begin != end; ++begin) {
    if (line > 72) {
      printf("|`|\n");
      line = 0;
    }
    line += printf("| %4d ", *begin);
  }
  printf("|\n");
}

/* array_is_sorted(begin, end): test if array is sorted */
int array_is_sorted(int *begin, int *end)
{
  for (; (end-begin) - 1 !=0;begin++)
  {
    if (*(begin) > (*(begin+1)))
    {
      return 0;
    }
  }
  return 1;
}
int array_sum(int *begin, int *end)
{
  int somme =0;
  for (;end-begin!=0;begin++)
  {
    somme+=*begin;
  }
  return somme;
}
void array_reverse(int *begin, int *end)
{
  //int len = ((begin + (end - begin))/2) ;
  end = end -1;
  for( ; *(begin) != *(begin + (end - begin) / 2)  ; )
  {
     swap(begin ,end);
     end--;
     begin++;
  }
}
void array_copy(int *dst, int *begin, int *end)
{
  for (;end - begin !=0; begin++)
  {
    *dst = *begin;
    dst++;
  }
}
/* array_sorted_fill(begin, end) */
void array_sorted_fill(int *begin, int *end)
{
  for (int i = 0; begin != end; ++begin, ++i)
    *begin = i;
}

/* array_random_fill(begin, end) */
void array_random_fill(int *begin, int *end)
{
  for (; begin != end; ++begin)
    *begin = random() % 10000;
}


void bench_sort(int *begin, int *end, sort_fun sort, const char *msg)
{
  struct timespec t0, t1;

  clock_gettime(CLOCK_MONOTONIC, &t0);
  sort(begin, end);
  clock_gettime(CLOCK_MONOTONIC, &t1);
  printf("%s:    \t%g\n", msg, time_gdiff(t0, t1));
  assert(array_is_sorted(begin, end));
}
int main(void)
{
  // Swap
  printf("======SWAP=======\n");
  int a = 1;
  int b = 2;
  printf("a = %d\n", a);
  printf("b = %d\n", b);

  swap(&a, &b);

  printf("a = %d\n", a);
  printf("b = %d\n", b);
  //Sum_of_Divisors
  printf("======Sum_of_Divisors=======\n");
  int x = 28;   // just an example of value
  size_t count; // you'll probably initialize it in your function
  printf("res = %d\n", sum_of_divisors(x, &count));
  printf("count = %zu\n", count);


  // ====== Array_test====
  int array[10] = {1,2,3,4,5,6,7,8,9,10}; // an example of array of size 10
  int *begin = array;
  int *end = begin + 10;
  printf("======Array_is_sorted=======\n");
  printf("Array is sorted = %d\n",array_is_sorted(begin,end));
  printf("======Array_Sum=======\n");
  array_print(begin,end);
  printf(" -> Sum = %d\n",array_sum(begin,end));
  printf("======Array_Reverse======\n");
  array_print(begin,end);
  printf(" After Reverse: ->\n");
  array_reverse(begin,end);
  array_print(begin,end);

  printf("======Array_Copy======");
  int array2[10]={};
  int *begin2 = array2;
  int *end2 = begin2 + 10;
  array_print(begin2,end2);
  printf(" After Copy: ->\n");
  array_copy(begin2,begin,end);
  array_print(begin2,end2);
  return 0;
}
