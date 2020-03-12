
////look at NaiveList.cpp and header file, on how to define method and void then can call it in main
//if main program works, can keep them in main, just do mode or at least sth in different classes
///have 2 versions of the grid. One is for the current generation, and the other is for computing the next generation (based on the current generation) without side effects.
#include <iostream>
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
  string mode;
  string choice;
  string outputfile;
  int neighborsMap=0;
  int neighborsRandom=0;



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
      string cellArrayMapnew[row][column];

     //read from map file and add cells to 2d array
     int rowMap = 0;
     int z = 0;
      while (getline(InputFile, Line))
      {
        rowMap = 0;
        z = 0;
         for(z=0; z < column; ++z)
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
     // classic mode
     if (mode=="classic")
     {
      cout << "classic mode" << endl;
         int Row=rowMap;
         int Column= z;

         // converting strings into values of 1 and 0
         int numberArrayMap[Row][Column];
         int nextgenMap[Row][Column];

       for (int k=0; k<1000; ++k){
         cout << "Generation # " << k << endl;
         cout << endl;
         for(int c = 0; c < Row; ++c){
           for(int d = 0; d < Column; ++d){
             if (cellArrayMap[c][d] == "X"){
               numberArrayMap[c][d] = 1;
            } else if(cellArrayMap[c][d] == "-"){
              numberArrayMap[c][d] = 0;
            }
           }
         }

         for(int c = 0; c < Row; ++c){
           for(int d = 0; d < Column; ++d){
             neighborsMap = numberArrayMap[Row-1][Column-1] + numberArrayMap[Row-1][Column] + numberArrayMap[Row-1][Column+1] + numberArrayMap[Row][Column+1] + numberArrayMap[Row+1][Column-1] + numberArrayMap[Row+1][Column]
             + numberArrayMap[Row+1][Column-1] + numberArrayMap[Row][Column-1];
//if there's only 1 neighbor, next generation in this space will be empty
             if(neighborsMap <= 1){
                nextgenMap[c][d] = 0;
                cellArrayMapnew[c][d] = "-";
              }//end if

   ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
            else if(neighborsMap == 2){
              if(numberArrayMap[c][d] == 1){
                nextgenMap[c][d] = 1;
                cellArrayMapnew[c][d] = "X";
              }//end if
              else if(numberArrayMap[c][d] == 0){
                nextgenMap[c][d] = 0;
                cellArrayMapnew[c][d] = "-";
              }//end else if
  }//end else if

  //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
            else if(neighborsMap == 3){
              if(numberArrayMap[c][d] == 1){
                  nextgenMap[c][d] = 1;
                  cellArrayMapnew[c][d] = "X";
                }//end if
              else if(numberArrayMap[c][d] == 0){
                  nextgenMap[c][d] = 1;
                  cellArrayMapnew[c][d] = "X";
    }//end else if
  }//end else if

  //if there's more than 4 neighbor,overpopulation, cell die
              else if(neighborsMap >= 4){
                 nextgenMap[c][d] = 0;
                 cellArrayMapnew[c][d] = "-";
          }//end else if

   }//end for
}//end for
    //cout << nextgenMap[c][d];
    for(int i = 0; i < row; ++i){
      for(int j = 0; j < column; ++j){
        if (nextgenMap[i][j] == 1){
          cout << "X";
        }else{
          cout << "-";
        }
      }
      cout << endl;
    }

      }
    }
//DONUT mode
       else if (mode=="doughnut")
       {
        cout << "doughnutmode: " << endl;
        int neighbors = 0;
        int Row=rowMap;
        int Column= z;
        string nextgenArray[Row][Column];
        int nextnumberArray[Row][Column];
        int numberArray[Row][Column];
        // in case row - 1 = -1
        int protectedr;
        int protectedc;

      for(int i = 0; i <= 100; i++){
        cout << endl;
        cout << "Generation # " << i << endl;
        for(int c = 0; c < Row; ++c){
          for(int d = 0; d < Column; ++d){
            if (cellArrayMap[c][d] == "X"){
              numberArray[c][d] = 1;
           } else if(cellArrayMap[c][d] == "-"){
             numberArray[c][d] = 0;
           }
          }
        }


        if (Row-1 == -1) {
            protectedr = Row-1;
          } else {
            protectedr = Row-1;
          }
          if (Column-1 == -1) {
            protectedc = Column-1;
          } else {
            protectedc = Column-1;
          }

          if(cellArrayMap[Row][(Column + 1) % column] == "X"){
            neighbors++;
          }
          if(cellArrayMap[(Row+1)%row][Column] == "X"){
            neighbors++;
          }
          if(cellArrayMap[(Row+1)%row][(Column+ 1) % column] == "X"){
            neighbors++;
          }
          if(cellArrayMap[(Row+1)%row][protectedc] == "X"){
            neighbors++;
          }
          if(cellArrayMap[Row][protectedc] == "X"){
            neighbors++;
          }
          if(cellArrayMap[protectedr][protectedc] == "X"){
            neighbors++;
          }
          if(cellArrayMap[protectedr][(Column+ 1) % column] == "X"){
            neighbors++;
          }
          if(cellArrayMap[protectedr][Column] == "X"){
            neighbors++;
          }


          for(int c = 0; c < Row; ++c){
            for(int d = 0; d < Column; ++d){
            //  cout << "n: " << neighbors << endl;
              if(neighbors < 2){
                 nextnumberArray[c][d] = 0;
                 nextgenArray[c][d] = "-";
               }//end if

     ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
             else if(neighbors == 2){
               if(numberArray[c][d] == 1){
                 nextnumberArray[c][d] = 1;
                 nextgenArray[c][d] = "X";
               }//end if
               else if(numberArray[c][d] == 0){
                 nextnumberArray[c][d] = 0;
                 nextgenArray[c][d] = "-";
               }//end else if
             }//end else if

     //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
             else if(neighbors == 3){
               if(numberArray[c][d] == 1){
                   nextnumberArray[c][d] = 1;
                   nextgenArray[c][d] = "X";
                 }//end if
               }else if(numberArray[c][d] == 0){
                   nextnumberArray[c][d] = 1;
                   nextgenArray[c][d] = "X";
                 }//end else if

     //if there's more than 4 neighbor,overpopulation, cell die
               else if(neighbors >= 4){
                  nextnumberArray[c][d] = 0;
                  nextgenArray[c][d] = "-";
                }
}
}

for(int i = 0; i < row; ++i){
  for(int j = 0; j < column; ++j){
    if (nextnumberArray[i][j] == 1){
      cout << "X";
    }else{
      cout << "-";
    }
  }
  cout << endl;
}
}



}  else if (mode=="mirror"){
              cout << "mirror mode: " << endl;

              int neighbors = 0;
              int Row=rowMap;
              int Column= z;
              string nextgenArray[Row][Column];
              int nextnumberArray[Row][Column];
              int numberArray[Row][Column];
              // in case row - 1 = -1
              int Rplus;
              int Rminus;
              int Cplus;
              int Cminus;

            for(int i = 0; i <= 100; i++){
              cout << endl;
              cout << "Generation # " << i << endl;
              for(int c = 0; c < Row; ++c){
                for(int d = 0; d < Column; ++d){
                  if (cellArrayMap[c][d] == "X"){
                    numberArray[c][d] = 1;
                 } else if(cellArrayMap[c][d] == "-"){
                   numberArray[c][d] = 0;
                 }
                }
              }

              if (Row+1 == row) {
                  Rplus = row;
                } else {
                  Rplus = Row+1;
                }
                if (Row-1 == -1) {
                    Rminus = Row;
                  } else {
                    Rminus = Row-1;
                }if (Column+1 == column) {
                    Cplus = column;
                } else {
                    Cplus = Column+1;
                }if (Column-1 == -1) {
                    Cminus = column;
                  } else {
                    Cminus = Column-1;
                  }
///////////////////////////////////////////////
// r minus and c


                if(cellArrayMap[Row][Cplus] == "X"){
                  neighbors++;
                }
                if(cellArrayMap[Row][Cminus] == "X"){
                  neighbors++;
                }
                if(cellArrayMap[Rminus][Cminus] == "X"){
                  neighbors++;
                }
                if(cellArrayMap[Rminus][Cplus] == "X"){
                  neighbors++;
                }
                if(cellArrayMap[Rminus][Column] == "X"){
                  neighbors++;
                }
                if(cellArrayMap[Rplus][Cplus] == "X"){
                  neighbors++;
                }
                if(cellArrayMap[Rplus][Cminus] == "X"){
                  neighbors++;
                }
                if(cellArrayMap[Rplus][Column] == "X"){
                  neighbors++;
                }

//////////////////////////////////

                for(int c = 0; c < Row; ++c){
                  for(int d = 0; d < Column; ++d){
                  //  cout << "n: " << neighbors << endl;
                    if(neighbors < 2){
                       nextnumberArray[c][d] = 0;
                       nextgenArray[c][d] = "-";
                     }//end if

           ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
                   else if(neighbors == 2){
                     if(numberArray[c][d] == 1){
                       nextnumberArray[c][d] = 1;
                       nextgenArray[c][d] = "X";
                     }//end if
                     else if(numberArray[c][d] == 0){
                       nextnumberArray[c][d] = 0;
                       nextgenArray[c][d] = "-";
                     }//end else if
                   }//end else if

           //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
                   else if(neighbors == 3){
                     if(numberArray[c][d] == 1){
                         nextnumberArray[c][d] = 1;
                         nextgenArray[c][d] = "X";
                       }//end if
                     }else if(numberArray[c][d] == 0){
                         nextnumberArray[c][d] = 1;
                         nextgenArray[c][d] = "X";
                       }//end else if

           //if there's more than 4 neighbor,overpopulation, cell die
                     else if(neighbors >= 4){
                        nextnumberArray[c][d] = 0;
                        nextgenArray[c][d] = "-";
                      }
      }
      }

      for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
          if (nextnumberArray[i][j] == 1){
            cout << "X";
          }else{
            cout << "-";
          }
        }
        cout << endl;
      }

/////////////////////////////////////////////
                }// end of for loop


        }
        else {
          cerr << "not a valid mode" << endl;
          exit(1);
       }
       // //pause between generation or output to a file
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
    int i=0;
    int j=0;
    string CellArrayRandom[row][column];
    string cellArrayRandomnew[i][j];
    for(j = 0; j < row; ++j){
      for(i=0; i < column; ++i)
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
     int Rowrandom = i;
     int Columnrandom = j;

     // converting strings into values of 1 and 0
     int numberArrayRandom[Rowrandom][Columnrandom];
     int nextgenRandom[Rowrandom][Columnrandom];

    for (int k=0; k<1000; ++k){
      cout << "Generation # " << k << endl;
       cout << endl;
     for(int e=0; e<Rowrandom; ++e){
       for(int c=0; c<Columnrandom; ++c){
         if(CellArrayRandom[i][j] == "X"){
           numberArrayRandom[i][j] = 1;
         }//end if
         else if(CellArrayRandom[i][j] == "-"){
           numberArrayRandom[i][j] = 0;
         }//end else if
       }//end for
     }//end for

     for(int e=0; e<Rowrandom; ++e){
       for(int c=0; c<Columnrandom; ++c){
         neighborsRandom = numberArrayRandom[Rowrandom-1][Columnrandom-1] + numberArrayRandom[Rowrandom-1][Columnrandom] + numberArrayRandom[Rowrandom-1][Columnrandom+1] + numberArrayRandom[Rowrandom][Columnrandom+1] + numberArrayRandom[Rowrandom+1][Columnrandom-1] + numberArrayRandom[Rowrandom+1][Columnrandom]
         + numberArrayRandom[Rowrandom+1][Columnrandom-1] + numberArrayRandom[Rowrandom][Columnrandom-1];
         //if there's only 1 cell, empty for the next generation
         if(neighborsRandom <=1){
           nextgenRandom[i][j] = 0;
           cellArrayRandomnew[i][j] = "-";
         }//end if
         //if there's 2 neighbor, next generation cells live on, if empty, still empty
         else if(neighborsRandom == 2){
           if (numberArrayRandom[i][j] == 1){
              nextgenRandom[i][j] = 1;
              cellArrayRandomnew[i][j] = "X";
           }//end if
           else if(numberArrayRandom[i][j] == 0){
             nextgenRandom[i][j] = 0;
             cellArrayRandomnew[i][j] = "-";
           }//else if
         }//end else if
//if there's 3 neighbor, next generation cells live on, if empty, generate a new cell
        else if(neighborsRandom == 3){
          if (numberArrayRandom[i][j] == 1){
             nextgenRandom[i][j] = 1;
             cellArrayRandomnew[i][j] = "X";
          }//end if
          else if(numberArrayRandom[i][j] == 0){
            nextgenRandom[i][j] = 1;
            cellArrayRandomnew[i][j] = "x";
          }//else if
        }//end else if
         else if(neighborsRandom >= 4){
           nextgenRandom[i][j] = 0;
           cellArrayRandomnew[i][j] = "-";
         }//end else if
       }//end for
     }//end for

     for(int g=0; g<row; ++g){
       for(int h=0; h<column; ++h){
         if(nextgenRandom[g][h] ==1){
           cout << "X";
         }//end if
         else{
           cout << "-";
         }//end else
       }//end for
       cout << endl;
     }//end for

    }
  }
  //donut mode under random assignment
    else if (mode=="doughnut")
    {
     cout << "doughnutmode" << endl;
     int neighborsrandomDoughnut = 0;
     int RowrandomDoughnut=i;
     int ColumnrandomDoughnut=j;
     string nextgenRandomDoughnut[RowrandomDoughnut][ColumnrandomDoughnut];
     int nextnumberArrayRandomDoughnut[RowrandomDoughnut][ColumnrandomDoughnut];
     int numberArrayRandomDoughnut[RowrandomDoughnut][ColumnrandomDoughnut];
     // in case row - 1 = -1
     int protectedrRandomDoughnut;
     int protectedcRandomDoughnut;

   for(int k = 0; k <= 100; k++){
     cout << endl;
     cout << "Generation # " << k << endl;
     for(int c = 0; c < RowrandomDoughnut; ++c){
       for(int d = 0; d < ColumnrandomDoughnut; ++d){
         if (CellArrayRandom[c][d] == "X"){
           numberArrayRandomDoughnut[c][d] = 1;
        } else if(CellArrayRandom[c][d] == "-"){
          numberArrayRandomDoughnut[c][d] = 0;
        }
       }
     }


     if (RowrandomDoughnut-1 == -1) {
         protectedrRandomDoughnut = RowrandomDoughnut-1;
       } else {
         protectedrRandomDoughnut = RowrandomDoughnut-1;
       }
       if (ColumnrandomDoughnut-1 == -1) {
         protectedcRandomDoughnut = ColumnrandomDoughnut-1;
       } else {
         protectedcRandomDoughnut = ColumnrandomDoughnut-1;
       }

       if(CellArrayRandom[RowrandomDoughnut][(ColumnrandomDoughnut + 1) % ColumnrandomDoughnut] == "X"){
         neighborsrandomDoughnut++;
       }
       if(CellArrayRandom[(RowrandomDoughnut+1)%RowrandomDoughnut][ColumnrandomDoughnut] == "X"){
         neighborsrandomDoughnut++;
       }
       if(CellArrayRandom[(RowrandomDoughnut+1)%RowrandomDoughnut][(ColumnrandomDoughnut+ 1) % ColumnrandomDoughnut] == "X"){
         neighborsrandomDoughnut++;
       }
       if(CellArrayRandom[(RowrandomDoughnut+1)%RowrandomDoughnut][protectedcRandomDoughnut] == "X"){
         neighborsrandomDoughnut++;
       }
       if(CellArrayRandom[RowrandomDoughnut][protectedcRandomDoughnut] == "X"){
         neighborsrandomDoughnut++;
       }
       if(CellArrayRandom[protectedrRandomDoughnut][protectedcRandomDoughnut] == "X"){
         neighborsrandomDoughnut++;
       }
       if(CellArrayRandom[protectedrRandomDoughnut][(ColumnrandomDoughnut+ 1) % ColumnrandomDoughnut] == "X"){
         neighborsrandomDoughnut++;
       }
       if(CellArrayRandom[protectedrRandomDoughnut][ColumnrandomDoughnut] == "X"){
         neighborsrandomDoughnut++;
       }


       for(int c = 0; c < RowrandomDoughnut; ++c){
         for(int d = 0; d < ColumnrandomDoughnut; ++d){
         //  cout << "n: " << neighbors << endl;
           if(neighborsrandomDoughnut < 2){
              nextnumberArrayRandomDoughnut[c][d] = 0;
              nextgenRandomDoughnut[c][d] = "-";
            }//end if

  ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
          else if(neighborsrandomDoughnut == 2){
            if(numberArrayRandomDoughnut[c][d] == 1){
              nextnumberArrayRandomDoughnut[c][d] = 1;
              nextgenRandomDoughnut[c][d] = "X";
            }//end if
            else if(numberArrayRandomDoughnut[c][d] == 0){
              nextnumberArrayRandomDoughnut[c][d] = 0;
              nextgenRandomDoughnut[c][d] = "-";
            }//end else if
          }//end else if

  //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
          else if(neighborsrandomDoughnut == 3){
            if(numberArrayRandomDoughnut[c][d] == 1){
                nextnumberArrayRandomDoughnut[c][d] = 1;
                nextgenRandomDoughnut[c][d] = "X";
              }//end if
            }else if(numberArrayRandomDoughnut[c][d] == 0){
                nextnumberArrayRandomDoughnut[c][d] = 1;
                nextgenRandomDoughnut[c][d] = "X";
              }//end else if

  //if there's more than 4 neighbor,overpopulation, cell die
            else if(neighborsrandomDoughnut >= 4){
               nextnumberArrayRandomDoughnut[c][d] = 0;
               nextgenRandomDoughnut[c][d] = "-";
             }
}
}

for(int i = 0; i < row; ++i){
for(int j = 0; j < column; ++j){
 if (nextnumberArrayRandomDoughnut[i][j] == 1){
   cout << "X";
 }else{
   cout << "-";
 }
}
cout << endl;
}
}



    }
    else if (mode=="mirror")
    {
     cout << "mirror mode" << endl;

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
