/* searching in array */

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

/*
 * searching for value
 */

/*
 * array_find(array, len, x): returns the position of x in array or len if not
 * present
 */
size_t array_find(int array[], size_t len, int x)
{
  for (size_t i=0; i<len;i++)
  {
    if (array[i]==x)
    {
      return i;
    }
  }
}

/*
 * array_bin_search(array, len, x): search in a sorted array using binary search
 * returns the position of x, or the expected position of x if not present
 */
size_t array_bin_search(int array[], size_t len, int x)
{

for (size_t i =0 ; i<len; i++)
{
  if (array[i]==x)
  {
    return i;
  }
}
return 0;
}

/*
 * Tests
 */

int array_random_sorted_fill(int array[], size_t len, int maxstep)
{
  int cur = 0;
  for (size_t i = 0; i < len; ++i) {
    int step = 1 + random() % maxstep;
    cur += step;
    array[i] = cur;
  }
  return cur;
}

typedef size_t (*search_fun)(int *, size_t, int);

static inline
void search_help(search_fun fun, int array[], size_t len, int x)
{
  printf("  searching %d: ", x);
  size_t i = fun(array, len, x);
  if (i < len)
    printf("array[%zu] = %d\n", i, array[i]);
  else
    printf("not found (%zu)\n", i);
}

static
void test_search(int array[], size_t len)
{
  int x;

  printf("*** Test value search ***\n");
  printf("**** Sorted array ****\n");
  array_sorted_fill(array, len, STEP);
  array_print(array, len, (len - 1) * STEP);
  x = array[0];
  search_help(array_find, array, len, x);
  x = array[len - 1];
  search_help(array_find, array, len, x);
  x = array[random() % len];
  search_help(array_find, array, len, x);
  x = len * STEP;
  search_help(array_find, array, len, x);


  printf("**** Reverse sorted array ****\n");
  array_reverse_sorted_fill(array, len, STEP);
  array_print(array, len, (len - 1) * STEP);
  x = array[0];
  search_help(array_find, array, len, x);
  x = array[len - 1];
  search_help(array_find, array, len, x);
  x = array[random() % len];
  search_help(array_find, array, len, x);
  x = len * STEP;
  search_help(array_find, array, len, x);

  printf("**** Random array ****\n");
  array_random_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  x = array[0];
  search_help(array_find, array, len, x);
  x = array[len - 1];
  search_help(array_find, array, len, x);
  x = array[random() % len];
  search_help(array_find, array, len, x);
  x = random() % (MAXVAL * 2);
  search_help(array_find, array, len, x);

}

static
void test_bin_search(int array[], size_t len)
{
  int x;

  printf("*** Test value binary search ***\n");

  printf("  founded index may not contain searched value\n");

  printf("**** Basic sorted array ****\n");
  array_sorted_fill(array, len, STEP);
  array_print(array, len, (len - 1) * STEP);
  x = array[0];
  search_help(array_bin_search, array, len, x);
  x = array[len - 1];
  search_help(array_bin_search, array, len, x);
  x = array[random() % len];
  search_help(array_bin_search, array, len, x);
  x = len * STEP;
  search_help(array_bin_search, array, len, x);

  printf("**** Basic sorted array ****\n");
  int maxval = array_random_sorted_fill(array, len, STEP);
  array_print(array, len, maxval);
  x = array[0];
  search_help(array_bin_search, array, len, x);
  x = array[len - 1];
  search_help(array_bin_search, array, len, x);
  x = array[random() % len];
  search_help(array_bin_search, array, len, x);
  x = random() % (maxval * 2);
  search_help(array_bin_search, array, len, x);

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

  test_search(array, len);
  printf("\n");

  test_bin_search(array, len);
  printf("\n");

  free(array);
  return 0;

}
