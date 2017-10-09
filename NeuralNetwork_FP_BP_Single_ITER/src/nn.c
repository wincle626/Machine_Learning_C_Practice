/*
 * nn.c
 *
 *  Created on: 9 Oct 2017
 *      Author: yunwu
 */


#include "nn.h"

void InitiateNetwork(net* Net, int layer_num, int *neural_per_layer)
{
  int l,i;

  Net->Layer = (layer**) calloc(layer_num, sizeof(layer*));
  Net->LayerNum = layer_num;

  for (l=0; l<layer_num; l++) {
    Net->Layer[l] = (layer*) malloc(sizeof(layer));

    Net->Layer[l]->NeuralNum     = neural_per_layer[l];
    Net->Layer[l]->Output     = (float*)  calloc(neural_per_layer[l]+1, sizeof(float));
    Net->Layer[l]->Error      = (float*)  calloc(neural_per_layer[l]+1, sizeof(float));
    Net->Layer[l]->Weight     = (float**) calloc(neural_per_layer[l]+1, sizeof(float*));
    Net->Layer[l]->WeightSave = (float**) calloc(neural_per_layer[l]+1, sizeof(float*));
    Net->Layer[l]->dWeight    = (float**) calloc(neural_per_layer[l]+1, sizeof(float*));
    Net->Layer[l]->Output[0]  = BIAS;

    if (l != 0) {
      for (i=1; i<=neural_per_layer[l]; i++) {
        Net->Layer[l]->Weight[i]     = (float*) calloc(neural_per_layer[l-1]+1, sizeof(float));
        Net->Layer[l]->WeightSave[i] = (float*) calloc(neural_per_layer[l-1]+1, sizeof(float));
        Net->Layer[l]->dWeight[i]    = (float*) calloc(neural_per_layer[l-1]+1, sizeof(float));
      }
    }
  }
  Net->InputLayer  = Net->Layer[0];
  Net->OutputLayer = Net->Layer[layer_num - 1];
  Net->Alpha       = 0.9;
  Net->Eta         = 0.25;
  Net->Gain        = 1;
}

void RandomWeights(net* Net)
{
  int l,i,j;

  for (l=1; l<Net->LayerNum; l++) {
    for (i=1; i<=Net->Layer[l]->NeuralNum; i++) {
      for (j=0; j<=Net->Layer[l-1]->NeuralNum; j++) {
        Net->Layer[l]->Weight[i][j] = RandomEqualFLOAT(-0.5, 0.5);
      }
    }
  }
}


void SetInput(net* Net, float* Input)
{
  int i;

  for (i=1; i<=Net->InputLayer->NeuralNum; i++) {
    Net->InputLayer->Output[i] = Input[i-1];
  }
}


void GetOutput(net* Net, float* Output)
{
  int i;

  for (i=1; i<=Net->OutputLayer->NeuralNum; i++) {
    Output[i-1] = Net->OutputLayer->Output[i];
  }
}

void SaveWeights(net* Net)
{
  int l,i,j;

  for (l=1; l<Net->LayerNum; l++) {
    for (i=1; i<=Net->Layer[l]->NeuralNum; i++) {
      for (j=0; j<=Net->Layer[l-1]->NeuralNum; j++) {
        Net->Layer[l]->WeightSave[i][j] = Net->Layer[l]->Weight[i][j];
      }
    }
  }
}

void RestoreWeights(net* Net)
{
  int l,i,j;

  for (l=1; l<Net->LayerNum; l++) {
    for (i=1; i<=Net->Layer[l]->NeuralNum; i++) {
      for (j=0; j<=Net->Layer[l-1]->NeuralNum; j++) {
        Net->Layer[l]->Weight[i][j] = Net->Layer[l]->WeightSave[i][j];
      }
    }
  }
}

void PropagateLayer(net* Net, layer* Lower, layer* Upper)
{
  int  i,j;
  float Sum;

  for (i=1; i<=Upper->NeuralNum; i++) {
    Sum = 0;
    for (j=0; j<=Lower->NeuralNum; j++) {
      Sum += Upper->Weight[i][j] * Lower->Output[j];
    }
    Upper->Output[i] = 1 / (1 + exp(-Net->Gain * Sum));
  }
}

void PropagateNet(net* Net)
{
  int l;

  for (l=0; l<Net->LayerNum-1; l++) {
    PropagateLayer(Net, Net->Layer[l], Net->Layer[l+1]);
  }
}

void ComputeOutputError(net* Net, float* Target)
{
  int  i;
  float Out, Err;

  Net->Error = 0;
  for (i=1; i<=Net->OutputLayer->NeuralNum; i++) {
    Out = Net->OutputLayer->Output[i];
    Err = Target[i-1]-Out;
    Net->OutputLayer->Error[i] = Net->Gain * Out * (1-Out) * Err;
    Net->Error += 0.5 * sqr(Err);
  }
}


void BackpropagateLayer(net* Net, layer* Upper, layer* Lower)
{
  int  i,j;
  float Out, Err;

  for (i=1; i<=Lower->NeuralNum; i++) {
    Out = Lower->Output[i];
    Err = 0;
    for (j=1; j<=Upper->NeuralNum; j++) {
      Err += Upper->Weight[j][i] * Upper->Error[j];
    }
    Lower->Error[i] = Net->Gain * Out * (1-Out) * Err;
  }
}


void BackpropagateNet(net* Net)
{
  int l;

  for (l=Net->LayerNum-1; l>1; l--) {
    BackpropagateLayer(Net, Net->Layer[l], Net->Layer[l-1]);
  }
}


void AdjustWeights(net* Net)
{
  int  l,i,j;
  float Out, Err, dWeight;

  for (l=1; l<Net->LayerNum; l++) {
    for (i=1; i<=Net->Layer[l]->NeuralNum; i++) {
      for (j=0; j<=Net->Layer[l-1]->NeuralNum; j++) {
        Out = Net->Layer[l-1]->Output[j];
        Err = Net->Layer[l]->Error[i];
        dWeight = Net->Layer[l]->dWeight[i][j];
        Net->Layer[l]->Weight[i][j] += Net->Eta * Err * Out + Net->Alpha * dWeight;
        Net->Layer[l]->dWeight[i][j] = Net->Eta * Err * Out;
      }
    }
  }
}

void SimulateNet(net* Net, float* Input, float* Output, float* Target, bool Training)
{
  SetInput(Net, Input);
  PropagateNet(Net);
  GetOutput(Net, Output);

  ComputeOutputError(Net, Target);
  if (Training) {
    BackpropagateNet(Net);
    AdjustWeights(Net);
  }
}
