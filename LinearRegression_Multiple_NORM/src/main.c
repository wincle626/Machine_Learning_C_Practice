/*
 * main.c
 *
 *  Created on: 27 Sep 2017
 *      Author: yunwu
 */

#include "lr.h"
#include "ultis.h"

int main(int argc, char** argv){

	float *x;
	float *y;
	float **X;
	float **X_trans;
	float **X_trans_X;
	float **X_trans_X_inv;
	float **X_trans_X_inv_X_trans;
	float *noise;
	float *theta_init;
	float *theta_est;
	noise = (float*) malloc(SIZE*sizeof(float));
	x = (float*) malloc((DIM+1)*SIZE*sizeof(float));
	y = (float*) malloc(SIZE*sizeof(float));
	theta_init = (float*) malloc((DIM+1)*sizeof(float));
	theta_est = (float*) malloc((DIM+1)*sizeof(float));
	X = (float**) malloc(SIZE*(DIM+1)*sizeof(float));
    for(int i = 0; i < SIZE; i++){
        X[i] = (float*)calloc((DIM+1), sizeof(float));
    }
	X_trans = (float**) malloc((DIM+1)*SIZE*sizeof(float));
    for(int i = 0; i < DIM+1; i++){
    	X_trans[i] = (float*)calloc(SIZE, sizeof(float));
    }
	X_trans_X = (float**) malloc((DIM+1)*(DIM+1)*sizeof(float));
    for(int i = 0; i < DIM+1; i++){
    	X_trans_X[i] = (float*)calloc((DIM+1), sizeof(float));
    }
	X_trans_X_inv = (float**) malloc((DIM+1)*(DIM+1)*sizeof(float));
    for(int i = 0; i < DIM+1; i++){
    	X_trans_X_inv[i] = (float*)calloc((DIM+1), sizeof(float));
    }
	X_trans_X_inv_X_trans = (float**) malloc((DIM+1)*SIZE*sizeof(float));
    for(int i = 0; i < DIM+1; i++){
    	X_trans_X_inv_X_trans[i] = (float*)calloc(SIZE, sizeof(float));
    }

	srand(time(NULL));

	random_vector_float(theta_init,DIM+1);
	print_vector_float((char*)"theta_init", theta_init, DIM+1);

	random_vector_float(x,DIM*SIZE);
//	print_vector_float((char*)"x", x, DIM*SIZE);

	linear_function_vec(x,theta_init,y,SIZE);
	random_vector_float_factor(noise, SIZE, 0.2);
	vector_add_float(y,noise,y,SIZE);
//	print_vector_float((char*)"y", y, SIZE);

	printf("\n\n----------------------\n\n");

	for(int i=0;i<SIZE;i++){
		for(int j=0;j<DIM+1;j++){
			if(j==0){
				X[i][j] = (float)1;
			}
			else{
				X[i][j] = x[i*DIM+j-1];
			}
		}
	}
//	print_matrix_float((char*) "X", X, SIZE, (DIM+1));

	matrix_transpose(X, X_trans, SIZE, (DIM+1));
//	print_matrix_float((char*) "X_trans", X_trans, (DIM+1), SIZE);

	matrix_multiple(X_trans, X, X_trans_X, (DIM+1), SIZE, (DIM+1));
//	print_matrix_float((char*) "X_trans_X", X_trans_X, (DIM+1), (DIM+1));

	matrix_inverse(X_trans_X, (DIM+1), X_trans_X_inv);
//	print_matrix_float((char*) "X_trans_X_inv", X_trans_X_inv, (DIM+1), (DIM+1));

	matrix_multiple(X_trans_X_inv, X_trans, X_trans_X_inv_X_trans, (DIM+1), (DIM+1), SIZE);
//	print_matrix_float((char*) "X_trans_X_inv_X_trans", X_trans_X_inv_X_trans, (DIM+1), SIZE);

	matrix_vector_multiple(X_trans_X_inv_X_trans, y, theta_est, (DIM+1), SIZE);
	print_vector_float((char*)"theta_est", theta_est, DIM+1);

	return 0;
}

