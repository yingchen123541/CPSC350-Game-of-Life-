
//look at NaiveList.cpp and header file, on how to define method and void then can call it in main
//if main program works, can keep them in main, just do mode or at least sth in different classes
///have 2 versions of the grid. One is for the current generation, and the other is for computing the next generation (based on the current generation) without side effects.
#include <iostream>
#include<fstream>
#include <sstream>
//#include "modes.h"
//#include "modes.cpp"

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
  string mode;
  string choice;
  string outputfile;


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

     //read from map file and add cells to 2d array
      while (getline(InputFile, Line))
      {
        int rowMap = 0;
         for(int z=0; z < column; ++z)
         {
           //divide each line into single letters
            cell = Line[z];
            if (cell == "-"){
              //add all empty cells to cellarray, this is the grid for first generation with mapfile
              cellArrayMap[rowMap][z] = "-";
            }
            else if (cell == "X"){
              //add all cells to cellarray
              cellArrayMap[rowMap][z] = "X";
            }
            else{
              cout << "Ya dun messed up, chief." << endl;
            }
            //print out all cells in mapfile
            cout << cellArrayMap[rowMap][z];
         }
         cout << endl;
         rowMap++;
      }
     //choose mode then calculate after getting 1st generation cell array (need to ask for mode in random assignent too)
       cout << "what kind of boundary mode do you want to run in? choose among classic mode, doughnut mode, and mirror Mode" << endl;
       cin >> mode;

       if (mode=="classic")
       {
        cout << "classic mode" << endl;
        // how to call the functions in main, what variables to use // undeclared identifier
        //cmode(cellArrayMap, cellArrayRandom, rowMap, z);
        //code for classic mode, get 1st generation grid then calculate
        //add in new cells and remove cells in certin spots in array
        //then update 1st generation cellArrayMap reference to 2nd generation cellArrayMap, then do 3rd generation using 2nd gen array
       }
       else if (mode=="doughnut")
       {
        cout << "doughnutmode" << endl;
        //code for doughnut mode, get 1st generation grid then calculate
        //add in new cells and remove cells in certin spots in array
      //then update 1st generation cellArrayMap reference to 2nd generation cellArrayMap, then do 3rd generation using 2nd gen array
       }
       else if (mode=="mirror")
       {
        cout << "mirror mode" << endl;
        //code for mirror mode, get 1st generation grid then calculate
        //add in new cells and remove cells in certin spots in array
      //then update 1st generation cellArrayMap reference to 2nd generation cellArrayMap, then do 3rd generation using 2nd gen array
       }
       else
       {
         cerr << "not a valid mode" << endl;
         exit(1);
       }
       //pause between generation or output to a file
         cout << "enter yes for pause between generations, enter no for output to a file" << endl;
         cin >> choice;

         if (choice=="yes")
         {
           //pause between generations
           cout << "pause between generations" << endl;
         }
         else if (choice=="no")
         {
           //output everything to a file
           ofstream OutputFile;
           cout << "enter an output file name" << endl;
           cin >> outputfile;
           OutputFile.open(outputfile);
         }
    }
    InputFile.close();

    //situation for random assignment
  }else if (answer=="no"){
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
    for(int j = 0; j < row; ++j){
      for(int i=0; i < column; ++i)
      {
       randomNumber = ((double)rand()/(double)RAND_MAX);
       //generate cells according to density to occupy blocks in array
       if (randomNumber<density)
       {
         CellArrayRandom[j][i] = "X";
       } else{
         CellArrayRandom[j][i] = "-";
       }
       //print out cellarrayRandom
         cout << CellArrayRandom[j][i];
      }
      cout << endl;
    }
    //prompt the user for mode under random assignment
    cout << "what kind of boundary mode do you want to run in? choose among classic mode, doughnut mode, and mirror Mode" << endl;
    cin >> mode;

    if (mode=="classic")
    {
     cout << "classic mode" << endl;
     //code for classic mode, get 1st generation grid then calculate
     //add in new cells and remove cells in certin spots in array
     //then update 1st generation CellArrayRandom reference to 2nd generation CellArrayRandom, then do 3rd generation using 2nd gen array
    }
    else if (mode=="doughnut")
    {
     cout << "doughnutmode" << endl;
     //code for doughnut mode, get 1st generation grid then calculate
     //add in new cells and remove cells in certin spots in array
   //then update 1st generation CellArrayRandom reference to 2nd generation CellArrayRandom, then do 3rd generation using 2nd gen array
    }
    else if (mode=="mirror")
    {
     cout << "mirror mode" << endl;
     //code for mirror mode, get 1st generation grid then calculate
     //add in new cells and remove cells in certin spots in array
   //then update 1st generation CellArrayRandom reference to 2nd generation CellArrayRandom, then do 3rd generation using 2nd gen array
    }
    else
    {
      cerr << "not a valid mode" << endl;
      exit(1);
    }

    //pause between generations or output to a file
    cout << "want a brief pause between generations?" << endl;
    cout << "want to press “Enter” to display the next generation? or want to output everything to a file?" << endl;
    cout << "enter yes for pause between generations, enter no for output to a file" << endl;
    cin >> choice;

    if (choice=="yes")
    {
      //pause between generations
      cout << "pause between generations" << endl;
    }
    else if (choice=="no")
    {
      //output everything to a file
      ofstream OutputFile;
      cout << "enter an output file name" << endl;
      cin >> outputfile;
      OutputFile.open(outputfile);
    }
  }
  return 0;
}
