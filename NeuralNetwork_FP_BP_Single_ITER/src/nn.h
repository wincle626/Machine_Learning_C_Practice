/*
 * nn.h
 *
 *  Created on: 9 Oct 2017
 *      Author: yunwu
 */

#ifndef SRC_NN_H_
#define SRC_NN_H_

#include <stdbool.h>
#include "utils.h"

typedef struct {                     /* A LAYER OF A NET:                     */
	int           NeuralNum;         /* - number of units in this layer       */
	float*         Output;        /* - output of ith unit                  */
	float*         Error;         /* - error term of ith unit              */
	float**        Weight;        /* - connection weights to ith unit      */
	float**        WeightSave;    /* - saved weights for stopped training  */
	float**        dWeight;       /* - last weight deltas for momentum     */
} layer;

typedef struct {                     /* A NET:                                */
	int LayerNum;
	layer**       Layer;         /* - layers of this net                  */
	layer*        InputLayer;    /* - input layer                         */
	layer*        OutputLayer;   /* - output layer                        */
	float          Alpha;         /* - momentum factor                     */
	float          Eta;           /* - learning rate                       */
	float          Gain;          /* - gain of sigmoid function            */
	float          Error;         /* - total net error                     */
} net;

#define BIAS          1

void InitiateNetwork(net* Net, int layer_num, int *neural_per_layer);
void RandomWeights(net* Net);
void SetInput(net* Net, float* Input);
void GetOutput(net* Net, float* Output);
void SaveWeights(net* Net);
void RestoreWeights(net* Net);
void PropagateLayer(net* Net, layer* Lower, layer* Upper);
void PropagateNet(net* Net);
void ComputeOutputError(net* Net, float* Target);
void BackpropagateLayer(net* Net, layer* Upper, layer* Lower);
void BackpropagateNet(net* Net);
void AdjustWeights(net* Net);
void SimulateNet(net* Net, float* Input, float* Output, float* Target, bool Training);

#endif /* SRC_NN_H_ */
