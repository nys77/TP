#include <stdio.h>
#include <math.h>

void transpose(double mat[], size_t lines, size_t cols, double res[])
{
   for(size_t i = 0; i < lines; i++)
   {
        for(size_t j = 0; j < cols; j++)
        {
          if (i!=j)
          {
          res[j + (i * cols)] = mat[i +(j*lines)];
          }
          else
          {
            res[j+(i*cols)]=mat[j+(i*cols)];
          }
        }
   }
}
void add(double mat1[], double mat2[], size_t lines, size_t cols, double res[])
{
  if (lines==cols)
  {
    for(size_t i = 0; i < lines; i++)

    {
         for(size_t j = 0; j < cols; j++)
         {
           res[j+ (i * cols)] = mat1[j+(i * cols)] + mat2[j+ (i * cols)];
         }
    }
  }
}
void mul(double m1[], double m2[], size_t n, size_t m, size_t p, double res[])
{
  if (n==p)
  {
    for(size_t i = 0; i < p; i++)
    {
         for(size_t j = 0; j < n; j++)
         {
           double temp = 0 ;
           for (size_t k= 0; k < m ;k++)
           {
             temp += (m1[k + (i * m)]) * (m2[j +(k * p)]);
           }
           res[j+(i*p)] = temp;
         }
    }
  }
}
void print_matrix(double mat[], size_t lines, size_t cols)
{

  for (size_t i= 0 ; i < lines ; i++)
  {
    printf("%c", '|');
    for (size_t j = 0 ; j < cols ; j++)
    {
     printf("%f", mat[j+ (i *cols)]);
     if (j== cols-1)
     {
        printf("%c", '|');
        printf("%c", '|\n');
     }
     else
     {
       printf("%c", '|');
     }
    }
  }
}
