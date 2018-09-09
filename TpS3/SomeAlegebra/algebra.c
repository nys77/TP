#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef double (*func_t)(double);
void vector_apply(func_t f, double vect[], size_t size, double res[])
{
  for (size_t i = 0 ; i < size ; i++)
  {
      double temp = vect[i];
      res[i]=  f(temp);
  }
}
void product(double M[], double v[], size_t m, size_t n, double res[])
{
  for (size_t i = 0 ; i< m   ; i++)
  {
    for (size_t j=0 ; j< n   ; j++)
    {
      res[i]= M[(i+j)*n] * v[j];
    }
  }
}
void vector_sum(double v1[], double v2[], size_t size, double res[])
{
  for (size_t i =0 ; i< size ; i++)
  {
    res[i]= v1[i]+v2[i];
  }
}
