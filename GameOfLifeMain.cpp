//////////how to do things (set array, define methods) in different classes instead of all in main???? answer in phone photo
//look at NaiveList.cpp and header file, on how to define method and void then can call it in main
//if main program works, can keep them in main, just do mode or at least sth in different classes
///have 2 versions of the grid. One is for the current generation, and the other is for computing the next generation (based on the current generation) without side effects.
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
  string answer;
  string MapFile;
  string cell;
  double randomNumber;


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
      //read the first line from input file
      getline(InputFile, Line, '\n');
      row = stoi(Line);
      cout << "row is " << row << endl;

      // read the second line from input file
      getline(InputFile, Line, '\n');
      column = stoi(Line);
      cout << "column is " << column << endl;

      string cellArrayMap[row][column];


      while (getline(InputFile, Line))
      {
        int colMap = 0;
         for(int z=0; z < row; ++z)
         {
           //divide each line into single letters
            cell = Line[z];
            if (cell == "-"){
              //add all empty cells to cellarray, this is the grid for first generation with mapfile
              cellArrayMap[z][colMap] = "-";
            }
            else if (cell == "X"){
              //add all cells to cellarray
              cellArrayMap[z][colMap] = "X";
            }
            else{
              cout << "Ya dun messed up, chief." << endl;
            }
            //print out all cells in mapfile
            cout << Line[z] << endl;
         }
         colMap++;
      }
    }
    InputFile.close();
  }else if (answer=="no"){
//situation for random assignment
    cout << "random assignment" << endl;
    cout << "enter the number of rows of the world" << endl;
    cin >> row;
    cout << "enter the number of columns of the world" << endl;
    cin >> column;
    //decimal value is greater than 0 and less than or equal to 1
    cout << "enter a decimal value between 0 and 1 representing the initial population density of the world" << endl;
    cin >> density;
    //create an array to hold all cells
    string CellArrayRandom[row][column];
    bool arraynotFull;
    //generate cells according to density to occupy blocks in array
    while (arraynotFull=true)
    {
      int colRandom = 0;
      for(int i=0; i < row; ++i)
      {
       randomNumber = ((double)rand()/(double)RAND_MAX);
       if (randomNumber<density)
       {
         CellArrayRandom[i][colRandom] = "X";
       } else{
         CellArrayRandom[i][colRandom] = "-";
       }
         cout << CellArrayRandom[i][colRandom] << "\n" << endl;
         if (colRandom>=column && i>=row)
         {
           arraynotFull=false;
         }
      }
      break;
      colRandom++;
    //  if (colRandom>=column)
    //  {
    //    arraynotFull=false;
    //  }
      //break;
    }
    //print out CellArrayRandom to check whether holding the cells right
    //for (int a = 0; a < row; a++)
    //   for (int b = 0; b < column; b++)
       //cout << CellArrayRandom[i][colRandom] << "\n" << endl;
  }









/*

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
