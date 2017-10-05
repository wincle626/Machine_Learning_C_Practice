/*
 * ultis.c
 *
 *  Created on: 21 Sep 2017
 *      Author: yunwu
 */

#include "ultis.h"
void print_vector_float(char* name, float *x, int size){

	for(int i=0;i<size;i++){
		printf("%s[%d]=%f,",name, i, x[i]);
	}
	printf("\n\n");

}

void print_matrix_float(char *name, float **x, int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%s[%d][%d]=%f,", name, i, j, x[i][j]);
		}
		printf("\n\n");
	}
}


void random_vector_float_factor(float *x, int size, float factor){
	int i;
	for(i=0;i<size;i++){
		x[i] = (float)factor*(float)RAND_MUL*(float)(rand()%RAND_DIV)/RAND_DIV;
	}
}

void random_vector_float(float *x, int size){
	int i;
	for(i=0;i<size;i++){
		x[i] = (float)RAND_MUL*(float)(rand()%RAND_DIV)/RAND_DIV;
	}
}

void vector_add_float(float *a, float *b, float *c, int size){
	int i;
	for(i=0;i<size;i++){
		c[i] = a[i] + b[i];
	}
}

void vector_sub_float(float *a, float *b, float *c, int size){
	int i;
	for(i=0;i<size;i++){
		c[i] = a[i] - b[i];
	}
}

float vector_sum_float(float *a, int size){
	int i;
	float sum = 0;
	for(i=0;i<size;i++){
		sum += a[i];
	}
	return sum;
}

void linear_vector_float(float *vec, int size){
	int i=0;
	for(i=0;i<size;i++){
		vec[i] = i;
	}
}

/*
   Recursive definition of determinate using expansion by minors.
*/
float determinant(float **a,int k)
{
	int i, j, m, n, c;
	float s = 1, det = 0;
	float **b;
	b = (float**) malloc(k*k*sizeof(float));
	for(i = 0; i < k; i++){
		b[i] = (float*)calloc(k, sizeof(float));
	}
	if (k == 1)
	{
		return (a[0][0]);
	}
	else
	{
		det = 0;
		for (c = 0; c < k; c++)
		{
			m = 0;
			n = 0;
			for (i = 0;i < k; i++)
			{
				for (j = 0 ;j < k; j++)
				{
					b[i][j] = 0;
					if (i != 0 && j != c)
					{
						b[m][n] = a[i][j];
						if (n < (k - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s * (a[0][c] * determinant(b, k - 1));
			s = -1 * s;
		}
	}

	return (det);
}

/*
   Find the cofactor matrix of a square matrix
*/
void cofactor(float **num, int f, float **inv)
{
	int p, q, m, n, i, j;
	float **b, **fac;
	b = (float**) malloc(f*f*sizeof(float));
	for(i = 0; i < f; i++){
		b[i] = (float*)calloc(f, sizeof(float));
	}
	fac = (float**) malloc(f*f*sizeof(float));
	for(i = 0; i < f; i++){
		fac[i] = (float*)calloc(f, sizeof(float));
	}
	for (q = 0;q < f; q++)
	{
		for (p = 0;p < f; p++)
		{
			m = 0;
			n = 0;
			for (i = 0;i < f; i++)
			{
				for (j = 0;j < f; j++)
				{
					if (i != q && j != p)
					{
						b[m][n] = num[i][j];
						if (n < (f - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
		}
	}
	transpose(num, fac, f, inv);
}

/*
   Transpose of a square matrix, do it in place
*/
void transpose(float **num, float **fac, int r, float **inverse)
{
	int i, j;
	float **b, d;
	b = (float**) malloc(r*r*sizeof(float));
	for(i = 0; i < r; i++){
		b[i] = (float*)calloc(r, sizeof(float));
	}

	for (i = 0;i < r; i++)
	{
		for (j = 0;j < r; j++)
		{
			b[i][j] = fac[j][i];
		}
	}
	d = determinant(num, r);
	for (i = 0;i < r; i++)
	{
		for (j = 0;j < r; j++)
		{
			inverse[i][j] = b[i][j] / d;
		}
	}
}

void matrix_inverse(float **a, int n, float **b){
	int d = determinant(a, n);
	if (d == 0){
		printf("\nInverse of Entered Matrix is not possible\n");
		exit(0);
	}
	else{
		cofactor(a, n, b);
	}
}

void matrix_multiple(float **a, float **b, float **c, int m , int n, int l){

	int i, j, k;
	float sum = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < l; j++) {
			for (k = 0; k < n; k++) {
				sum = sum + a[i][k]*b[k][j];
//				printf("%f += %f * %f\n", sum, a[i][k],b[k][j]);
			}

			c[i][j] = sum;
			sum = 0;
		}
	}
}

void matrix_vector_multiple(float **a, float *b, float *c, int m, int n){
	int i, j;
	float sum = 0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			sum += a[i][j] * b[j];
//			printf("%f += %f * %f\n", sum, a[i][n],b[n]);
		}
		c[i] = sum;
		sum = 0;
	}
}

void vector_multiple(float *a, float **c, int n){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			c[i][j] = a[i] * a[j];
		}
	}
}

void matrix_transpose(float **a, float **b, int m, int n){

   int i,j;

   for (i=0;i<m;i++) {
	  for (j=0;j<n;j++) {
		 b[j][i] = a[i][j];
	  }
   }

}
