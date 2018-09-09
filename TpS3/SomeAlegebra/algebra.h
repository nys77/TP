/*
 * algebra.h: some useful linear algebra operations
 *
 * 2017 Marwan Burelle / EPITA
 */

#ifndef _SOMEALGEBRA_ALGEBRA_H_
#define _SOMEALGEBRA_ALGEBRA_H_

/*
 * func_t: function pointer type
 */
typedef double (*func_t)(double);

/*
 * vector_apply(f, vect, size, res)
 * applies a function to all element on a vector of size n
 * for i in 0..size, res[i] = f[vect[i]]
 */
void vector_apply(func_t f, double vect[], size_t size, double res[]);

/*
 * product(M, v, m, n, res)
 * computes res = M * v
 * where M is a m X n matrix, v is of length n and res of length m
 */
void product(double M[], double v[], size_t m, size_t n, double res[]);

/*
 * vector_sum(v1, v2, size, res)
 * computes res = v1 + v2
 * with res, v1 and v2 three vector of lenght size
 */
void vector_sum(double v1[], double v2[], size_t size, double res[]);

#endif /* _SOMEALGEBRA_ALGEBRA_H_ */
