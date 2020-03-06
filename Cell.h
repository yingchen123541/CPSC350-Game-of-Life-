#include <iostream>

using namespace std;

class Cell
{
  public:
    Cell();//default constructor
    {
      //tutor: do i do string for array?
      CellArray = new string[row][column];
      row = 0;
      column = 0;
    }

    Cell(int row, column);//overload constructor
    {

    }

    ~Cell();//destructor
//void is not returning anything, int will return an int
    void insertFront(string Cell)
    //loop through all cell and see whether each cell is alive
    bool CellAlive(string Cell)
    int removeFront();
    int search();
    int removeAtPos(int pos);

    bool isEmpty();
    void printList();


}
