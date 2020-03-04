//////////how to do things (set array, define methods) in different classes instead of all in main????

#include "GameOfLife.h"
#include "GameOfLife.cpp"
#include<fstream>
#include <sstream>

using namespace std;

int main (){
  std:: string Line;
  int row=0;
  int column=0;
  double density=0;
  string CellArray[row][column];
  string answer;
  string MapFile;

  cout << "do you want to provide a map file of the world, or you want random assignment? " << endl;
  cout << "type yes for map file, no for random assignment" << endl;
  cin >> answer;

//situation when wants to open a map file
  if (answer=="yes")
  {
    //provide file path to open file
    cout << "enter the file you want to open" << endl;
    cin >> MapFile;
    ifstream InputFile;
    InputFile.open(MapFile);
    if(!InputFile)
    {
      //output error message
      cerr << "unable to open file" << endl;
      exit(1);
    }
      //input file is successfully opened
    else if(InputFile)
    {
      //read through the input file line by line
      while (getline(InputFile, Line))
      {
        ////////tutor: how do i only read the 1st and 2nd line from a file?
        ///////and how to start reading from the 3rd line to put things in 2d array?
        ///////want to only read the 1st line and put in row
        for(int a=0; a<1; a++)
        {
            //convert Line to an int
          stringstream convert(Line);
          convert >> row;
          cout << "row is" << row << endl;
        }
        //////only read the 2nd line to put in column
        for(int a=0; a<2; a++)
        {
          stringstream convert(Line);
          convert >> column;
          cout << "column is" << row << endl;
        }
          CellArray[row][column];
        ////////then read from the 3rd line to the end to add cells to array
      }
    }
    InputFile.close();
  }

//situation for random assignment
  else if (answer==no)
  {
    cout << "random assignment" << endl;
    cout << "enter the number of rows of the world" << endl;
    cin >> row;
    cout << "enter the number of columns of the world" << endl;
    cin >> column;
    //decimal value is greater than 0 and less than or equal to 1
    cout << "enter a decimal value between 0 and 1 representing the initial population density of the world" << endl;
    cin >> density;
    //create an array to hold all cells
    CellArray[row][column];

    /////////generate cells according to density to occupy blocks in array, how????
  }











  cout << "what kind of boundary mode do you want to run in? choose among classic mode, doughnut mode, and mirror Mode" << endl;
  cin >> mode;
  cout << "want a brief pause between generations?" << endl;
  cout << "want to press “Enter” to display the next generation?" << endl;
  cout << "or want to output everything to a file?" << endl;
  cout << "enter yes for pause between generations, enter no for output to a file" << endl;
  cin >> choice;

  if (mode==classic mode)
  {

  }
  else if (mode==doughnut mode)
  {

  }
  else if (mode==mirror Mode)
  {

  }
  else
  {
    cerr << "not a valid mode" << endl;
    exit(2);
  }
//pause between generations or output to a file
  if (choice==yes)
  {
    //pause between generations
  }
  else if (choice==no)
  {
    //output everything to a file
    ofstream OutputFile;
    cout << "enter an output file name" << endl;
    cin >> outputfile;
    OutputFile.open(outputfile);
  }


  return 0;
}
