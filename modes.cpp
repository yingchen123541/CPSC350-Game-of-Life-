#include "modes.h"

//classic mode
int cmode(string cellArrayMap[], string cellArrayRandom[], int rowMap, int z){
  //initizlize the number of neighbor around a space
  int neighbors = 0;
  //move X and - into number array so that turn X and - into 0 and 1
  int numberArray[rowMap][z];
  //array for next generation
  int nextgen[rowMap][z];

// converting strings into values of 1 and 0
  for(int n =0; n< rowMap; n++){
    for(int c = 0; c < z; c++){
      if(cellArrayMap[n][c] == "X"){
        //1 means the space is occupied by a cell
        numberArray[n][c] = 1;
      }
      //0 means the space is empty
      else if(cellArrayMap[n][c] == "-"){
        numberArray[n][c] = 0;
      }
    }
  }

//classic mode
  for(int i=0; i < rowMap; i++){
    for(int a=0; a < z; a++){
      //check the amount of neighbour around a space
      neighbors = numberArray[rowMap-1][z-1] + numberArray[rowMap-1][z] + numberArray[rowMap-1][z+1] + numberArray[rowMap][z+1] +numberArray[rowMap+1][z-1] + numberArray[rowMap+1][z]
      + numberArray[rowMap+1][z-1]+ numberArray[rowMap][z-1];
    }
  }

cout << neighbors << endl;

  for(int i=0; i < rowMap; i++){
    for(int a=0; a < z; a++){
//if there's only 1 neighbor, next generation in this space will be empty
      if(neighbors <= 1){
        nextgen[i][a] = 0;
      }
      ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
      else if(neighbors == 2){
        if(numberArray[i][a] == 1){
          nextgen[i][a] = 1;
        }
        // if empty still empty
        else if(numberArray[i][a] == 0){
          nextgen[i][a] = 0;
        }
      }
      //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
      else if(neighbors == 3){
        if(numberArray[i][a] == 1){
          nextgen[i][a] = 1;
        }
        // if empty the still lives on
        else if(numberArray[i][a] == 0){
          nextgen[i][a] = 1;
      }
    }
      //if there's more than 4 neighbor,overpopulation, cell die
      else if(neighbors >= 4){
        nextgen[i][a] = 0;
      }
  }
}
//return the next generation array 
return nextgen[][];
}

// donut mode
