/* quick_sort.c : simple quick sort implementation */

# include <stdlib.h>
# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "helper.h"
# include "quick_sort.h"

void swap(int *a, int *b)
{
  int temp = *a;
  *a=*b;
  *b=temp;
}

int* partition(int *begin, int *end)
{
  int* pivot = (begin + (end - begin) / 2);
  int pval = *(pivot);
  swap(pivot,end-1);
  pivot = begin;
  for (;end-begin!=0; begin++)
  {
    if (*(begin) < pval)
    {
      swap(pivot, begin);
      //pval =*(pivot);
      pivot ++;
    }
  }
  swap((pivot), (end-1));
  return pivot;
}
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
void quick_sort(int *begin, int *end)
{
  if (end - begin != 0)
  {
    int* pivot = partition(begin, end);
    quick_sort(begin, pivot);
    quick_sort(pivot+1, end);
  }
}
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
void hybrid_sort(int *begin, int *end)
{
  if (end - begin < 2 || array_is_sorted(begin, end))
    return;
  quick_sort(begin, end);
}
int main (void)
{
  printf("=====QuickSort=====\n");
  int array2[9] = {14,12,4,5,36,47,18,29,110}; // an example of array of size 10
  int *begin2 = array2;
  int *end2 = begin2 + 9;
  array_print(begin2,end2);
  printf("\n");
  hybrid_sort(begin2,end2);
  array_print(begin2,end2);
  return 0;
}
