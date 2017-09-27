/*
 * main.c
 *
 *  Created on: 21 Sep 2017
 *      Author: yunwu
 */

#include "lr.h"
#include "ultis.h"
#include "gfx.h"

int main(int argc, char** argv){

	int i, j;
	int ysize = 100;
	int xsize = 100;
	int size = 100;
	char c;

	float *x;
	float *y;
	float *noise;
	float theta0_est;
	float theta1_est;
	float theta0_init = 2.3;
	float theta1_init = 1.5;
	x = (float*) malloc(size*sizeof(float));
	y = (float*) malloc(size*sizeof(float));
	noise = (float*) malloc(size*sizeof(float));
	srand(time(NULL));
	random_vector_float(x,size);
	linear_function_vec(x,theta0_init,theta1_init,y,size);
	random_vector_float_factor(noise, size, 0.0);
	vector_add_float(y,noise,y,size);


//	float b0 = 2.3;
//	float b1 = 1.5;
//	float alpha1 = 0.01;
//	float err1;
//	for (int i = 0; i < size*ITERATION_BOUND; i ++) {
//	    int idx = i % size;
//	    float p = b0 + b1 * x[idx];
//	    err1 = p - y[idx];
//	    b0 = b0 - alpha1 * err1;
//	    b1 = b1 - alpha1 * err1 * x[idx];
//	}

	printf("theta0=%f,theta1=%f\n",theta0_init,theta1_init);
	gradient_descent(SITA0_INIT,SITA1_INIT,LEARN_RATE,
			x,y,size,&theta0_est,&theta1_est);
	printf("theta0=%f,theta1=%f\n",theta0_est,theta1_est);
//	for(i=0,j=0;i<size;i++,j++){
//		printf("x[%d]=%f, y[%d]=%f\n",i,x[i],j,y[j]);
//	}
//
//
//	gfx_open(xsize,ysize,"Linear Regression Demo");
//	gfx_color(100,200,100);
//	for(i=0,j=0;i<size;i++,j++){
//		gfx_point(x[i],y[i]);
//	}
////	gfx_color(0,200,100);
//	gfx_line(0,linear_function(0,theta0_est,theta1_est),10,linear_function(10,theta0_est,theta1_est));
//	while(1) {
//		// Wait for the user to press a character.
//		c = gfx_wait();
//
//		// Quit if it is the letter q.
//		if(c=='q') break;
//	}

	return 0;
}
