/* helper.h: helper functions */

# ifndef EPITA_IP_ARRAY_HELPER_H_
# define EPITA_IP_ARRAY_HELPER_H_

# define _XOPEN_SOURCE 500

# include <stdlib.h>
# include <time.h>

/* swap(a,b): swap memory location content */
void swap(int *a, int *b);

int sum_of_divisors(int x, size_t *count);
/* array_print(begin, end) print integer array */
/* with a fixed padding of 4 chars             */
void array_print(int *begin, int *end);

/* array_is_sorted(begin, end): test if array is sorted */
int array_is_sorted(int *begin, int *end);

/* array_random_fill(begin, end) */
void array_random_fill(int *begin, int *end);

int array_sum(int *begin, int *end);

void array_reverse(int *begin, int *end);

void array_copy(int *dst, int *begin, int *end);
/* inlined code, all is ok */
static inline
double time_gdiff(struct timespec t0, struct timespec t1)
{
  double s = t1.tv_sec - t0.tv_sec;
  return s + (t1.tv_nsec - t0.tv_nsec) * 1e-9;
}

typedef void (*sort_fun)(int*, int*);

void bench_sort(int *begin, int *end, sort_fun sort, const char *msg);

# endif /* EPITA_IP_ARRAY_HELPER_H_ */
