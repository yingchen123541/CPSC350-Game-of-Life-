#include "GameOfLife.h"
#include "GameOfLife.cpp"
#include<fstream>
#include <string>

using namespace std;

int main (int argc, char **argv){
  int row;
  int column;
  string CellArray[row][column];
  string Line;
  string answer;
  string MapFile;

  cout << "do you want to provide a map file of the world, or you want random assignment? " << endl;
  cout << "type yes for map file, no for random assignment" << endl;
  cin >> answer;

  if (answer=="yes")
  {
    //provide file path to open file
    cout << "enter the file you want to open " << endl;
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
        for(int a=0; a<1; a++)
        {
          //convert Line to an int
          row = stoi(Line);
        }
        for(int a=0; a<2; a++)
        {
          column = stoi(Line);
        }
        cout << "row is" << row << endl;
        cout << "column is" << column << endl;
      }
    }
  }
/*
  else if (answer==no)
  {
    cout << "random assignment" << endl;
    cout << "enter the number of rows of the world" << endl;
    cin >> row;
    cout << "enter the number of columns of the world" << endl;
    cin >> column;
    //decimal value is greater than 0 and less than or equal to 1
    cout << "enter a decimal value representing the initial population density of the world" << endl;
    //create an array to hold all cells
    CellArray[row][column];
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

*/
  return 0;
}
