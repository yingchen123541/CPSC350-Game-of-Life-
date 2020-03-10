#include "modes.h"

//classic mode
int cmode(string cellArrayMap[], string cellArrayRandom[], int rowMap, int z){
  int neighbors = 0;
  int numberArray[rowMap][z];
  int nextgen[rowMap][z];

// converting strings into values of 1 and 0
  for(int n =0; n< rowMap; n++){
    for(int c = 0; c < z; c++){
      if(cellArrayMap[n][c] == "X"){
        numberArray[n][c] = 1;
      }
      else if(cellArrayMap[n][c] == "-"){
        numberArray[n][c] = 0;
      }
    }
  }

//classic mode
  for(int i=0; i < rowMap; i++){
    for(int a=0; a < z; a++){
      neighbors = numberArray[rowMap-1][z-1] + numberArray[rowMap-1][z] + numberArray[rowMap-1][z+1] + numberArray[rowMap][z+1] +numberArray[rowMap+1][z-1] + numberArray[rowMap+1][z]
      + numberArray[rowMap+1][z-1]+ numberArray[rowMap][z-1];
    }
  }

cout << neighbors << endl;

  for(int i=0; i < rowMap; i++){
    for(int a=0; a < z; a++){

      if(neighbors <= 1){
        nextgen[i][a] = 0;
      }
      else if(neighbors == 2){
        if(numberArray[i][a] == 1){
          nextgen[i][a] = 1;
        }
        // if empty still emptyxs
        else if(numberArray[i][a] == 0){
          nextgen[i][a] = 0;
        }
      }
      else if(neighbors == 3){
        if(numberArray[i][a] == 1){
          nextgen[i][a] = 1;
        }
        // if empty the still lives on
        else if(numberArray[i][a] == 0){
          nextgen[i][a] = 1;
      }
    }
      //overpopulation
      else if(neighbors >= 4){
        nextgen[i][a] = 0;
      }
  }
}
return nextgen[][];
}

// donut mode
