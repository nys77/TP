/*
 * algebra_test.c: some useful linear algebra operations, tests
 *
 * 2017 Marwan Burelle / EPITA
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "algebra.h"

/*
 * sigmoid(x) the classical sigmoid function
 */
double sigmoid(double x)
{
  return 1 / (1 + exp(-x));
}

/*
 * 2D rotation of v by theta centered on the origin
 */
void rotation(double theta, double v[], double r[])
{
  double M[] = {
    cos(theta), -sin(theta),
    sin(theta), cos(theta)
  };
  product(M, v, 2, 2, r);
}

void layer(double W[], double b[], double a[], size_t m, size_t n, double r[])
{
  product(W, a, m, n, r);
  vector_sum(b, r, m, r);
  vector_apply(sigmoid, r, m, r);
}

double W[] = {
  6.36634445, 6.36769295
};

double b[] = {
  -9.00631428
};

void test(void)
{
  double a[] = {1,1};
  double r[] = {0};
  layer(W, b, a, 1, 2, r);
  printf("1, 1 -> %g\n", r[0]);
  a[0] = 0; a[1] = 0;
  layer(W, b, a, 1, 2, r);
  printf("0, 0 -> %g\n", r[0]);
  a[0] = 1; a[1] = 0;
  layer(W, b, a, 1, 2, r);
  printf("1, 0 -> %g\n", r[0]);
  a[0] = 0; a[1] = 1;
  layer(W, b, a, 1, 2, r);
  printf("0, 1 -> %g\n", r[0]);
}

int main()
{
  test();
  return 0;
}
