/* main_tests.c: testing your code */

# define _XOPEN_SOURCE 500

# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "helper.h"
# include "insert_sort.h"
# include "quick_sort.h"


int main(int argc, char *argv[])
{
  srandom(time(NULL));
  // default to length = 16
  size_t len = 16;
  if (argc > 1)
    len = strtoul(argv[1], NULL, 10);
  int *array = calloc(len, sizeof (int));
  int *copy = calloc(len, sizeof (int));
  int *begin = array, *end = array + len;

  // a sorted array for basic tests
  for (int *cur = begin + 1; cur < end; ++cur)
    *cur = *(cur - 1) + 1;

  /* use bench_sort to test and bench sort algorithms on presorted array */

  // random fill the array
  // copy in order to test sorting algorithm on the same array
  array_random_fill(begin, end);
  memcpy(copy, begin, len * sizeof (int));

  /* use bench_sort to test and bench sort algorithms on random array */

  // free memory
  free(array);
  free(copy);
  return 0;
}
