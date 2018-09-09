
/* tests_tools.h */
/* Tools for testing array functions */

# ifndef EPITA_IP_ARRAY_TESTS_TOOLS_H_
# define EPITA_IP_ARRAY_TESTS_TOOLS_H_

/*
 * Needed in order to use some POSIX functions
 * see feature_test_macros(7)
 */
# define _XOPEN_SOURCE 500

# include <stdio.h>
# include <stdlib.h>

/*
 * helper functions (array fill, display ... )
 * all functions are statically inlined, no links dependencies
 */

/*
 * array_random_fill(array, len, maxval): fill array with random values
 * maxval is the maximum random value
 */
static inline
void array_random_fill(int array[], size_t len, int maxval)
{
  for (size_t i = 0; i < len; ++i)
    array[i] = random() % maxval;
}

/*
 * array_sorted_fill(array, len, step): fill array with sorted value
 * step is the difference between values
 */
static inline
void array_sorted_fill(int array[], size_t len, int step)
{
  int cur = 0;
  for (size_t i = 0; i < len; ++i, cur += step)
    array[i] = cur;
}

/*
 * array_reverse_sorted_fill(array, len, step): fill array with values in
 * reverse order
 * step is the difference between values
 */
static inline
void array_reverse_sorted_fill(int array[], size_t len, int step)
{
  int cur = (len - 1) * step;
  for (size_t i = 0; i < len; ++i, cur -= step)
    array[i] = cur;
}

/*
 * int_len(int x): number of decimal digit
 */
static inline
int int_len(int x)
{
  int len = 0;
  for (; x > 0; x /= 10)
    len += 1;
  return len;
}

/*
 * array_print(array, len): print the array
 */
static inline
void array_print(int array[], size_t len, int maxval)
{
  int line = 0;
  int intlen = int_len(maxval);
  for (size_t i = 0; i < len; ++i) {
    if (line > 72) {
      printf("|\n");
      line = 0;
    }
    line += printf("| %*d ", intlen, array[i]);
  }
  printf("|\n");
}

#define check(C__) ((C__) ? "\x1b[44mOK\x1b[0m" : "\x1b[41mKO\x1b[0m")

# endif /* EPITA_IP_ARRAY_TESTS_TOOLS_H_ */
