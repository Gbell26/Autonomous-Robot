#include <math.h>

const int trainX = 40; //size of training set ie # of inputs
const int inputNeurons = 2; //two input nodes
const int hiddenNeurons = 3; //two hidden neurons
const int outputNeurons = 1; //# of outputs 
const float learningRate = 0.1; // learning rate
const float initWeightMax = 0.5; // max value to  initialize weights w/
const float momentum = 0.9;
const float success = 0.01; // finish training when error is less than this val


float error;
float Accum;
float randomNum;
float sum;
int count;

int RandomizedIndex[trainX];
float inputNormalize[trainX][inputNeurons];

float hiddenLayerOutputs[hiddenNeurons]; 
float outputLayerOutputs[outputNeurons];
float hiddenWeights[inputNeurons+1][hiddenNeurons];
float outputWeights[hiddenNeurons+1][outputNeurons];
float hiddenDelta[hiddenNeurons];
float outputDelta[outputNeurons];
float changeHiddenWeights[inputNeurons+1][hiddenNeurons];
float changeOutputWeights[hiddenNeurons+1][outputNeurons];



//training sets for XOR 
const float Input[trainX][inputNeurons] = {
  {74, 112},//1 0
  {103, 36},//0 1 
  {80, 73},//0 2
  {52, 84},//1 3
  {100, 31},//0 4
  {68, 44},//0 5
  {89, 90},//1 6
  {59, 25},//0 7
  {97, 104},//1 8
  {24, 13},//0 9
  {24, 94},//1 10
  {88, 91},//1 11
  {94, 39},//0 12
  {62, 26},//0 13
  {91, 67},//0 14
  {105, 27},//0 15
  {85, 58},//0 16
  {22, 37},//1 17
  {65, 43},//0 18
  {78, 65},//0 19
  {47, 40},//0 20
  {55, 45},//0 21
  {60, 73},//1 22
  {54, 90} , //1 23 
  {78, 68},//0 24
  {12, 40},//1 25
  {5, 54},//1 26
  {7, 59},//1 27
  {46, 47},//1 28
  {39, 10},//0 29
  {24, 36},//1 30
  {83, 59},//0 31
  {94, 102},//1 32
  {6, 10},//1 33
  {0, 40},//1 34
  {16, 69},//1 35
  {43, 55},//1 36
  {64, 31},//0 37
  {86, 90},//1 38
  {20, 23}//1 39
}; 

const byte Target[trainX][outputNeurons] = {
  { 1}, // 0
  { 0}, //1  
  { 0}, //2
  { 1}, //3
  { 0}, //4
  { 0}, //5
  { 1}, //6
  { 0}, //7
  { 1}, //8
  { 0},//9
  { 1},//10
  { 1},//11
  { 0},//12
  { 0},//13
  { 0},//14
  { 0},//15
  { 0},//16
  { 1},//17
  { 0},//18
  { 0},//19 
  { 0},//20
  { 0},//21
  { 1},//22
  { 1},//23
  { 0},//24
  { 1},//25
  { 1},//26
  { 1},//27
  { 1},//28
  { 0},//29
  { 1},//30
  { 0},//31
  { 1},//32
  { 1},//33
  { 1},//34
  { 1},//35
  { 1},//36
  { 0},//37
  { 1},//38
  { 1} //39
};




float trainedHiddenWeights[inputNeurons + 1][hiddenNeurons] = {
    { -54.01, 37.70, -15.60},
    {54.69, -37.93, 15.67},
    {-0.06, 0.04, -0.47}
  };

float trainedOutputWeights[hiddenNeurons + 1][outputNeurons] = {
    {28.69},
    {-20.47},
    {8.63},
    {-6.08}
  };


void train(){
for (int x = 0; x < trainX; x++){
    inputNormalize[x][0] = Input[x][0]/1000;
    inputNormalize[x][1] = Input[x][1]/1000;
}



 for( int p = 0 ; p < trainX ; p++ ) {    
      RandomizedIndex[p] = p ;
}

//initialize hiddenWeights && hidden change weights 
for ( int i = 0 ; i < hiddenNeurons; i++ ) {    
    for( int j = 0 ; j <= inputNeurons; j++ ) { 
      changeHiddenWeights[j][i] = 0.0;
      randomNum = float(random(100))/100;
      hiddenWeights[j][i] = 2.0 * ( randomNum - 0.5 ) * initWeightMax;
    }
  }

// initialize output changeWeights && output weights
  for ( int i = 0 ; i < outputNeurons ; i ++ ) {    
    for( int j = 0 ; j <= hiddenNeurons ; j++ ) {
      changeOutputWeights[j][i] = 0.0 ;  
      randomNum = float(random(100))/100;        
      outputWeights[j][i] = 2.0 * ( randomNum - 0.5 ) * initWeightMax;
    }
  }

for (int epoch = 0; epoch < 1000000; epoch++){

    //Randomize order
  for( int p = 0 ; p < trainX ; p++) {
      int q = random(trainX);
      int r = RandomizedIndex[p] ; 
      RandomizedIndex[p] = RandomizedIndex[q] ; 
      RandomizedIndex[q] = r ;
    }

  error = 0.0;
  //Forward Propagate:

  //cycle through each input ie training size
  for(int x = 0; x < trainX; x++){
    count = RandomizedIndex[x];
    // hidden layer activations
    for(int i = 0; i < hiddenNeurons; i++){
      //start with hidden bias
      sum = hiddenWeights[inputNeurons][i];
      for(int j = 0; j< inputNeurons; j++){
      //add weighted input
        sum += inputNormalize[count][j] * hiddenWeights[j][i];
      }
      //compute sigmoid of sum of hidden layers for hiddenOutput
      hiddenLayerOutputs[i] = 1.0/(1.0 + exp(-sum));
    } 


    //compute outputLayer activation && errors
    for(int k = 0; k < outputNeurons; k++){
      //start with output bias
      sum = outputWeights[hiddenNeurons][k];
      for(int l = 0; l < hiddenNeurons; l++){
        //add weighted input from hiddenlayeroutputs
        sum += hiddenLayerOutputs[l] * outputWeights[l][k];
      }
      //calculate sigmoid
      outputLayerOutputs[k] = 1.0/(1.0 + exp(-sum));
      //calculate errors && add them to output delta for backprop

      outputDelta[k] = (Target[count][k] - outputLayerOutputs[k]) * 
      outputLayerOutputs[k] * (1.0 - outputLayerOutputs[k]);

      //record current error to check if training is done
      error += 0.5 * (Target[count][k] - outputLayerOutputs[k]) * 
      (Target[count][k] - outputLayerOutputs[k]);
    }
  //END FORWARD PROP

  //START BACKPROP
  //calculate amount change for weights
    for(int m = 0; m < hiddenNeurons; m++){
      Accum = 0.0;
      for(int n = 0; n < outputNeurons; n++){
        Accum += outputWeights[m][n] * outputDelta[n];
      }
      hiddenDelta[m] = Accum * hiddenLayerOutputs[m] * (1.0 - hiddenLayerOutputs[m]);
    }

    //update hidden weights
    for(int o = 0; o < hiddenNeurons; o++){
      changeHiddenWeights[inputNeurons][o] = learningRate * hiddenDelta[o] + momentum * changeHiddenWeights[inputNeurons][o];
      hiddenWeights[inputNeurons][o] += changeHiddenWeights[inputNeurons][o]; 
      for(int p = 0; p < inputNeurons; p++){
        changeHiddenWeights[p][o] = learningRate * inputNormalize[count][p] * hiddenDelta[o] + momentum * changeHiddenWeights[p][o];
        hiddenWeights[p][o] += changeHiddenWeights[p][o];
      }
    }


    //update outputweights
    for(int q = 0; q < outputNeurons; q++){
      changeOutputWeights[hiddenNeurons][q] = learningRate * outputDelta[q] + momentum * changeOutputWeights[hiddenNeurons][q];
      outputWeights[hiddenNeurons][q] += changeOutputWeights[hiddenNeurons][q]; 
      for(int r = 0; r < hiddenNeurons; r++){
        changeOutputWeights[r][q] = learningRate * hiddenLayerOutputs[r] * outputDelta[q] + momentum * changeOutputWeights[r][q];
        outputWeights[r][q] += changeOutputWeights[r][q];
      }
    }
    //end backprop
  }
  if (error < success) {break;}
}

//print hidden and output wieghts to be used be getResults() to pretrain model
  Serial.println("Hidden Weights:");
  for(int i = 0; i<=inputNeurons; i++){
    for(int j = 0; j < hiddenNeurons; j++){
      Serial.print(hiddenWeights[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }

  Serial.println("Output Weights:");
  for(int i = 0; i<=hiddenNeurons; i++){
    for(int j = 0; j < outputNeurons; j++){
      Serial.print(outputWeights[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }
}


float getResult(float val1, float val2){
  float input[1][2];

  input[0][0] = val1/1000;
  input[0][1] = val2/1000;

  //feedforward
  for( int i = 0 ; i < hiddenNeurons; i++ ) {    
      sum = trainedHiddenWeights[inputNeurons][i] ;
      for(int j = 0 ; j < inputNeurons; j++ ) {
        sum += input[0][j] * trainedHiddenWeights[j][i];
      }
      hiddenLayerOutputs[i] = 1.0/(1.0 + exp(-sum)) ;
    }

    for(int i = 0 ; i < outputNeurons ; i++ ) {    
      sum = trainedOutputWeights[hiddenNeurons][i] ;
      for( int j = 0 ; j < hiddenNeurons; j++ ) {
        sum += hiddenLayerOutputs[j] * trainedOutputWeights[j][i] ;
      }
      outputLayerOutputs[i] = 1.0/(1.0 + exp(-sum)) ; 
    }

  //return output
  return outputLayerOutputs[0];
}
  






