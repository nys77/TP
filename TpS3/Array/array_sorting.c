/* array_sorting.c : sorting arrays */

# define _XOPEN_SOURCE 500

# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "tests_tools.h"

# define MAXVAL 100
# define STEP 10

/*
 * In all following functions parameters array and len are defined as:
 * array: an integer array
 * len: the length of the array, must be greater than 0
 */

/* tools for sorting */

/*
 * array_is_sorted(array, len): returns true if array is sorted in increasing
 * order
 */
int array_is_sorted(int array[], size_t len)
{
  for(size_t i=0;i<len - 1;i++)
  {
    if (array[i]>array[i+1])
       {
         return 0;
       }
  }
  return 1;
}

/*
 * array_swap(array, i, j): swap cell value at position i and j
 */
void array_swap(int array[], size_t i, size_t j)
{
  int temp = array[i];
  array[i]=array[j];
  array[j]=temp;
}

/* Selection sort */

/*
 * array_select_sort(array, len): sort array using select sort
 */
void array_select_sort(int array[], size_t len)
{
  size_t min_val;
  size_t min_index;
  for (size_t i =0 ; i<len;i++)
  {

    for (size_t j =i;j < len;j++)
    {
      if (j==i)
      {
          min_val=array[j];
          min_index= j;
      }
      else
      {
        if (array[j] < array[min_val])
      {
        min_val=array[j];
        min_index=j;
      }
    }
    }
    int temp = array[min_index];
    array[min_index]=array[i];
    array[i]=temp;
  }
}

/*
 * Tests
 */


static inline
double time_gdiff(struct timespec t0, struct timespec t1)
{
  double s = t1.tv_sec - t0.tv_sec;
  s += (t1.tv_nsec - t0.tv_nsec) * 1e-9;
  return s;
}

static inline
void sort_help(int array[], size_t len, int maxval)
{
  struct timespec t0, t1;
  printf("Array before sort:\n");
  array_print(array, len, maxval);
  printf("  ... sorting ...\n");
  clock_gettime(CLOCK_MONOTONIC, &t0);
  array_select_sort(array, len);
  clock_gettime(CLOCK_MONOTONIC, &t1);
  printf("Array after sort:\n");
  array_print(array, len, maxval);
  printf("  time for sorting: %gs\n", time_gdiff(t0, t1));
  printf("  sort check: %s\n", check(array_is_sorted(array, len)));
}

void test_sorting(int array[], size_t len)
{
  printf("*** Sorted array ***\n");
  array_sorted_fill(array, len, STEP);
  sort_help(array, len, STEP * (len - 1));

  printf("\n*** Reverse sorted array ***\n");
  array_reverse_sorted_fill(array, len, STEP);
  sort_help(array, len, STEP * (len - 1));

  printf("\n*** Random array ***\n");
  array_random_fill(array, len, MAXVAL);
  sort_help(array, len, MAXVAL);
}

/*
 * main
 */

int main(int argc, char *argv[])
{

  srandom(time(NULL));

  size_t len;
  if (argc < 2)
    errx(1, "must provide array length");
  len = strtoul(argv[1], NULL, 10);
  int *array = calloc(len, sizeof (int));

  test_sorting(array, len);
  printf("\n");

  free(array);
  return 0;

}
