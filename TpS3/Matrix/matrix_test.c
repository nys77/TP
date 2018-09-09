/*
 * matrix_test.c: standard matrix operations, very quick tests
 *
 * 2017 Marwan Burelle / EPITA
 */

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

/*
 * some matrices and their dimensions
 */

#define lines1 3
#define cols1  4

double m1[] = {
  1.0, 2.0, 3.0, 4.0,
  5.0, 6.0, 7.0, 8.0,
  9.0, 10.0, 11.0, 12.0
};

#define lines2 4
#define cols2  3

double m2[] = {
  1.0, 2.0, 3.0,
  4.0, 5.0, 6.0,
  7.0, 8.0, 9.0,
  10.0, 11.0, 12.0
};

#define lines3 3
#define cols3  3
double m3[] = {
  1, 2, 3,
  4, 5, 6,
  7, 8, 9
};

double id[] = {
  1.0, 0.0, 0.0,
  0.0, 1.0, 0.0,
  0.0, 0.0, 1.0
};

/*
 * some empty matrices with correct dimensions for results
 */

/*
 * lines1 X cols1 or cols1 X lines1 matrix
 */
double res1[ lines3 * cols3 ];

/*
 * lines1 X cols2 matrix (for m1 * m2 results, or m3 * m3 or m3 * id)
 */
double res2[ lines1 * cols2 ];

double res3 [ lines1 * 4];


int main()
{
  printf("m1 =\n");
  print_matrix(m1, lines1, cols1);
  printf("\nm2 =\n");
  print_matrix(m2, lines2, cols2);
  printf("\nm3 =\n");
  print_matrix(m3, lines3, cols3);
  printf("\nid =\n");
  print_matrix(id, lines3, cols3);

  /* TEST YOUR OPERATIONS HERE */
  printf("\ntranspose =\n");
  transpose(m3, lines3,  cols3,  res1);
  print_matrix (res1 ,lines3, cols3);
  printf("\naddition =\n");
  add( m1,  m2, lines1,  cols2,  res2);
  print_matrix (res2 ,lines1 , cols2);
  printf("\nmultiplication =\n");
  mul( m2,  m1,  cols1 , lines1,  lines2,  res3);
  print_matrix (res3 ,lines2 , cols1);


  return 0;
}
