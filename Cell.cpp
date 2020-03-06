#include "Cell.h"

//default constructor
Cell::Cell(){
  CellArray = new string[row][column];
  row = 0;
  column = 0;
}

  //overload constructor
Cell::Cell(int row, int column){
  CellArray = new string[row][column];
    row =row;
    column = column;
  }

Cell::~Cell(){
//try without [] if doesn't compile
  delete CellArray[];
}

void insertFront(string Cell)
{
  
}
