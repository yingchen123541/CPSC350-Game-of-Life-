#include <iostream>
#include<fstream>
#include <sstream>

/** GameOfLifeMain.cpp
* Name1: Yuki Chen
* Student ID1: 2320235
* Email1: yingchen@chapman.edu
*
* Name2: Nidhi Vedantam
* Student ID2: 2328859
* Email2: vedantam@chapman.edu
*
* Assignment3  The Game Of Life
* purpose: simulate the game of life in classic mode, doughnut mode, and mirror Mode
* get input from user to make the initial generation of cells
* output the new generations to a file
* Version 3.0
* Date: March 12, 2020
*
*/

using namespace std;

int main (){
  //define variable types and initialize variavles
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

// get input from users
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
      //convert string to int
      row = stoi(Line);
      cout << "row is " << row << endl;

      // read the second line from input file
      getline(InputFile, Line, '\n');
      //convert string to int
      column = stoi(Line);
      cout << "column is " << column << endl;
//initialize array to hold first generation cells
      string cellArrayMap[row][column];
      string cellArrayMapnew[row][column];

     //initialize row and column values
     int rowMap = 0;
     int z = 0;
     //read from the file starting from the third line
      while (getline(InputFile, Line))
      {
        rowMap = 0;
        z = 0;
        //loop through all lines
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
//prompt the user for mode
     cout << "what kind of boundary mode do you want to run in? choose among classic mode, doughnut mode, and mirror Mode" << endl;
     cin >> mode;
     // classic mode
     if (mode=="classic")
     {
        cout << "classic mode: " << endl;
  //prompt for pause between generations or output to a file
        cout << "enter yes for pause between generations, enter no for output to a file" << endl;
        cin >> choice;
        //situation for paude between generation
         if (choice=="yes")
         {
           //pause between generations
           cout << "pausing between generations.." << endl;
           int Row=rowMap;
           int Column= z;

           //initialize next generation array and number array
           int numberArrayMap[Row][Column];
           int nextgenMap[Row][Column];
// print out 1000 generations
         for (int k=0; k<1000; ++k){
             cout << "Generation # " << k << endl;
             cout << endl;
           for(int c = 0; c < Row; ++c){
             for(int d = 0; d < Column; ++d){
               //convert X to 1, - to 0
               if (cellArrayMap[c][d] == "X"){
                 numberArrayMap[c][d] = 1;
              } else if(cellArrayMap[c][d] == "-"){
                numberArrayMap[c][d] = 0;
              }
             }
           }
       // add up the number of neighbors around cell
           for(int c = 0; c < Row; ++c){
             for(int d = 0; d < Column; ++d){
               neighborsMap = numberArrayMap[Row-1][Column-1] + numberArrayMap[Row-1][Column] + numberArrayMap[Row-1][Column+1] + numberArrayMap[Row][Column+1] + numberArrayMap[Row+1][Column-1] + numberArrayMap[Row+1][Column]
               + numberArrayMap[Row+1][Column-1] + numberArrayMap[Row][Column-1];
  //if there's only 1 neighbor, next generation in this space will be empty
               if(neighborsMap <= 1){
                  nextgenMap[c][d] = 0;
                  //store cells in next generation array
                  cellArrayMapnew[c][d] = "-";
                }//end if

     ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
              else if(neighborsMap == 2){
                if(numberArrayMap[c][d] == 1){
                  nextgenMap[c][d] = 1;
                  //store cells in next generation array
                  cellArrayMapnew[c][d] = "X";
                }//end if
                else if(numberArrayMap[c][d] == 0){
                  nextgenMap[c][d] = 0;
                  //store cells in next generation array
                  cellArrayMapnew[c][d] = "-";
                }//end else if
              }//end else if

    //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
              else if(neighborsMap == 3){
                if(numberArrayMap[c][d] == 1){
                    nextgenMap[c][d] = 1;
                    //store cells in next generation array
                    cellArrayMapnew[c][d] = "X";
                  }//end if
                else if(numberArrayMap[c][d] == 0){
                    nextgenMap[c][d] = 1;
                    //store cells in next generation array
                    cellArrayMapnew[c][d] = "X";
                  }           //end else if
                }//end else if

    //if there's more than 4 neighbor,overpopulation, cell die
                else if(neighborsMap >= 4){
                   nextgenMap[c][d] = 0;
                   //store cells in next generation array
                   cellArrayMapnew[c][d] = "-";
                 }//end else if

               }//end for
             }//end for

      for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
          if (nextgenMap[i][j] == 1){
            //convert 1 back to x
              cout << "X";
          }else{
            //convert 0 back to -
              cout << "-";
          }
        }
          cout << endl;
      }

        }
         }
         else if (choice=="no")
         {
           //output everything to a file
           ofstream OutputFile;
           cout << "enter an output file name" << endl;
           cin >> outputfile;
           //open output file
           OutputFile.open(outputfile);
           cout << "outputting to file...." << endl;
//initialize variables
           int Row=rowMap;
           int Column= z;

           //initialize number array and next generation array
           int numberArrayMap[Row][Column];
           int nextgenMap[Row][Column];
//loop 1000 times
         for (int k=0; k<1000; ++k){
             OutputFile << "Generation # " << k << endl;
             //output generations to a file
             OutputFile << endl;
           for(int c = 0; c < Row; ++c){
             for(int d = 0; d < Column; ++d){
               //convert x to 1, - to 0
               if (cellArrayMap[c][d] == "X"){
                 numberArrayMap[c][d] = 1;
              } else if(cellArrayMap[c][d] == "-"){
                numberArrayMap[c][d] = 0;
              }
             }
           }

           for(int c = 0; c < Row; ++c){
             for(int d = 0; d < Column; ++d){
               //add up the number of neighbors around a cell
               neighborsMap = numberArrayMap[Row-1][Column-1] + numberArrayMap[Row-1][Column] + numberArrayMap[Row-1][Column+1] + numberArrayMap[Row][Column+1] + numberArrayMap[Row+1][Column-1] + numberArrayMap[Row+1][Column]
               + numberArrayMap[Row+1][Column-1] + numberArrayMap[Row][Column-1];
  //if there's only 1 neighbor, next generation in this space will be empty
               if(neighborsMap <= 1){
                  nextgenMap[c][d] = 0;
                  //store cells in next generation array
                  cellArrayMapnew[c][d] = "-";
                }//end if

     ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
              else if(neighborsMap == 2){
                if(numberArrayMap[c][d] == 1){
                  nextgenMap[c][d] = 1;
                  //store cells in next generation array
                  cellArrayMapnew[c][d] = "X";
                }//end if
                else if(numberArrayMap[c][d] == 0){
                  nextgenMap[c][d] = 0;
                  //store cells in next generation array
                  cellArrayMapnew[c][d] = "-";
                }//end else if
    }//end else if

    //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
              else if(neighborsMap == 3){
                if(numberArrayMap[c][d] == 1){
                    nextgenMap[c][d] = 1;
                    //store cells in next generation array
                    cellArrayMapnew[c][d] = "X";
                  }//end if
                else if(numberArrayMap[c][d] == 0){
                    nextgenMap[c][d] = 1;
                    //store cells in next generation array
                    cellArrayMapnew[c][d] = "X";
      }//end else if
    }//end else if

    //if there's more than 4 neighbor,overpopulation, cell die
                else if(neighborsMap >= 4){
                   nextgenMap[c][d] = 0;
                   //store cells in next generation array
                   cellArrayMapnew[c][d] = "-";
            }//end else if

     }//end for
  }//end for

      for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
          if (nextgenMap[i][j] == 1){
            //convert 1 back to X, 0 back to -
              OutputFile << "X";
          }else{
              OutputFile << "-";
          }
        }
          OutputFile << endl;
      }

        }
      }
      //close input file
      InputFile.close();

    }// end of classic

//DONUT mode
else if (mode=="doughnut")
       {
        cout << "doughnutmode: " << endl;
//prompt the user to pause between generation or output to a file
        cout << "enter yes for pause between generations, enter no for outputing to a file" << endl;
        cin >> choice;
        if (choice=="yes")
        {
          //pause between generation
          cout << "pause between generations" << endl;
          //initialize variables
          int neighbors = 0;
          int Row=rowMap;
          int Column= z;
          string nextgenArray[Row][Column];
          int nextnumberArray[Row][Column];
          int numberArray[Row][Column];
          // in case row - 1 = -1
          int protectedr;
          int protectedc;
//loop 1000 times
        for(int i = 0; i <= 1000; i++){
          cout << endl;
          cout << "Generation # " << i << endl;
          for(int c = 0; c < Row; ++c){
            for(int d = 0; d < Column; ++d){
              //convert X to 1, - to 0
              if (cellArrayMap[c][d] == "X"){
                numberArray[c][d] = 1;
             } else if(cellArrayMap[c][d] == "-"){
               numberArray[c][d] = 0;
             }
            }
          }
       //situations when cells are at the edges
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
//add the number of neighbors around cell
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
            //if there's one or fewer neighbor, cell will be empty
                if(neighbors < 2){
                   nextnumberArray[c][d] = 0;
                   //store cells in next generation array
                   nextgenArray[c][d] = "-";
                 }//end if

       ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
               else if(neighbors == 2){
                 if(numberArray[c][d] == 1){
                   nextnumberArray[c][d] = 1;
                   //store cells in next generation array
                   nextgenArray[c][d] = "X";
                 }//end if
                 else if(numberArray[c][d] == 0){
                   nextnumberArray[c][d] = 0;
                   //store cells in next generation array
                   nextgenArray[c][d] = "-";
                 }//end else if
               }//end else if

       //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
               else if(neighbors == 3){
                 if(numberArray[c][d] == 1){
                     nextnumberArray[c][d] = 1;
                     //store cells in next generation array
                     nextgenArray[c][d] = "X";
                   }//end if
                 }else if(numberArray[c][d] == 0){
                     nextnumberArray[c][d] = 1;
                     //store cells in next generation array
                     nextgenArray[c][d] = "X";
                   }//end else if

       //if there's more than 4 neighbor,overpopulation, cell die
                 else if(neighbors >= 4){
                    nextnumberArray[c][d] = 0;
                    //store cells in next generation array
                    nextgenArray[c][d] = "-";
                  }
  }
  }

  for(int i = 0; i < row; ++i){
    for(int j = 0; j < column; ++j){
      if (nextnumberArray[i][j] == 1){
        //convert 1 back to X, 0 back to -
        cout << "X";
      }else{
        cout << "-";
      }
    }
    cout << endl;
  }
  }
        }
        else if (choice=="no")
        {
          //output to a file
          ofstream OutputFile;
          cout << "enter an output file name" << endl;
          cin >> outputfile;
          OutputFile.open(outputfile);
          //open output file
          cout << "outputting to file..." << endl;
          //initialize variables
        int neighbors = 0;
        int Row=rowMap;
        int Column= z;
        string nextgenArray[Row][Column];
        int nextnumberArray[Row][Column];
        int numberArray[Row][Column];
        // in case row - 1 = -1
        int protectedr;
        int protectedc;
//print out 1000 generations
      for(int i = 0; i <= 1000; i++){
        OutputFile << endl;
        OutputFile << "Generation # " << i << endl;
        for(int c = 0; c < Row; ++c){
          for(int d = 0; d < Column; ++d){
            if (cellArrayMap[c][d] == "X"){
              //convert X to 1, - to 0
              numberArray[c][d] = 1;
           } else if(cellArrayMap[c][d] == "-"){
             numberArray[c][d] = 0;
           }
          }
        }

//situations when cells are at the edges
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
    //add the number of neighbors around cell
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
            //if there is one or fewer neighbor, empty cell
              if(neighbors < 2){
                 nextnumberArray[c][d] = 0;
                 //store cells in next generation array
                 nextgenArray[c][d] = "-";
               }//end if

     ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
             else if(neighbors == 2){
               if(numberArray[c][d] == 1){
                 nextnumberArray[c][d] = 1;
                 //store cells in next generation array
                 nextgenArray[c][d] = "X";
               }//end if
               else if(numberArray[c][d] == 0){
                 nextnumberArray[c][d] = 0;
                 //store cells in next generation array
                 nextgenArray[c][d] = "-";
               }//end else if
             }//end else if

     //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
             else if(neighbors == 3){
               if(numberArray[c][d] == 1){
                   nextnumberArray[c][d] = 1;
                   //store cells in next generation array
                   nextgenArray[c][d] = "X";
                 }//end if
               }else if(numberArray[c][d] == 0){
                   nextnumberArray[c][d] = 1;
                   //store cells in next generation array
                   nextgenArray[c][d] = "X";
                 }//end else if

     //if there's more than 4 neighbor,overpopulation, cell die
               else if(neighbors >= 4){
                  nextnumberArray[c][d] = 0;
                  //store cells in next generation array
                  nextgenArray[c][d] = "-";
                }
}
}

for(int i = 0; i < row; ++i){
  for(int j = 0; j < column; ++j){
    if (nextnumberArray[i][j] == 1){
      //convert 1 and 0 back to X and -
      OutputFile << "X";
    }else{
      OutputFile << "-";
    }
  }
  OutputFile << endl;
}
}
OutputFile.close();
}


//mirror mode
}  else if (mode=="mirror"){
              cout << "mirror mode: " << endl;
//prompt to pause between generations or output to a file
              cout << "enter yes for pause between generations, enter no for output to a file" << endl;
              cin >> choice;

               if (choice=="yes")
               {
                 //pause between generations
                 cout << "pause between generations" << endl;
                 //initialize variable
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
//loop 1000 times
               for(int i = 0; i <= 1000; i++){
                 cout << endl;
                 cout << "Generation # " << i << endl;
                 for(int c = 0; c < Row; ++c){
                   for(int d = 0; d < Column; ++d){
                     //convert X to 1, - to 0
                     if (cellArrayMap[c][d] == "X"){
                       numberArray[c][d] = 1;
                    } else if(cellArrayMap[c][d] == "-"){
                      numberArray[c][d] = 0;
                    }
                   }
                 }
//cells with reflection
                 if (Row+1 == row) {
                     Rplus = row;
                   } else {
                     Rplus = Row+1;
                   }
                   //cells at edges
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
  // add the number of neighbors around cells
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


                   for(int c = 0; c < Row; ++c){
                     for(int d = 0; d < Column; ++d){
                     //if one or fewer neighbor, empty cell
                       if(neighbors < 2){
                          nextnumberArray[c][d] = 0;
                          //store cells in next generation array
                          nextgenArray[c][d] = "-";
                        }//end if

              ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
                      else if(neighbors == 2){
                        if(numberArray[c][d] == 1){
                          nextnumberArray[c][d] = 1;
                          //store cells in next generation array
                          nextgenArray[c][d] = "X";
                        }//end if
                        else if(numberArray[c][d] == 0){
                          nextnumberArray[c][d] = 0;
                          //store cells in next generation array
                          nextgenArray[c][d] = "-";
                        }//end else if
                      }//end else if

              //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
                      else if(neighbors == 3){
                        if(numberArray[c][d] == 1){
                            nextnumberArray[c][d] = 1;
                            //store cells in next generation array
                            nextgenArray[c][d] = "X";
                          }//end if
                        }else if(numberArray[c][d] == 0){
                            nextnumberArray[c][d] = 1;
                            //store cells in next generation array
                            nextgenArray[c][d] = "X";
                          }//end else if

              //if there's more than 4 neighbor,overpopulation, cell die
                        else if(neighbors >= 4){
                           nextnumberArray[c][d] = 0;
                           //store cells in next generation array
                           nextgenArray[c][d] = "-";
                         }
         }
         }

         for(int i = 0; i < row; ++i){
           for(int j = 0; j < column; ++j){
             if (nextnumberArray[i][j] == 1){
               //convert 1 back to x, 0 back to -
               cout << "X";
             }else{
               cout << "-";
             }
           }
           cout << endl;
         }



                   }
               }
               //output to a file
               else if (choice=="no")
               {
                 //output everything to a file
                 ofstream OutputFile;
                 cout << "enter an output file name" << endl;
                 cin >> outputfile;
                 //open output file
                 OutputFile.open(outputfile);
                 cout << "outputting to file...." << endl;
//initialize variables
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
//loop 1000 times
            for(int i = 0; i <= 1000; i++){
              OutputFile << endl;
              OutputFile << "Generation # " << i << endl;
              for(int c = 0; c < Row; ++c){
                for(int d = 0; d < Column; ++d){
                  //convert x to 1, - to 0
                  if (cellArrayMap[c][d] == "X"){
                    numberArray[c][d] = 1;
                 } else if(cellArrayMap[c][d] == "-"){
                   numberArray[c][d] = 0;
                 }
                }
              }
//cell from reflection
              if (Row+1 == row) {
                  Rplus = row;
                } else {
                  Rplus = Row+1;
                }
                //cells are at edges
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
//add the number of neighbors around cell
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

                for(int c = 0; c < Row; ++c){
                  for(int d = 0; d < Column; ++d){
                  //if there's 1 or fewer cell around, empty cell
                    if(neighbors < 2){
                       nextnumberArray[c][d] = 0;
                       //store cells in next generation array
                       nextgenArray[c][d] = "-";
                     }//end if

           ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
                   else if(neighbors == 2){
                     if(numberArray[c][d] == 1){
                       nextnumberArray[c][d] = 1;
                       //store cells in next generation array
                       nextgenArray[c][d] = "X";
                     }//end if
                     else if(numberArray[c][d] == 0){
                       nextnumberArray[c][d] = 0;
                       //store cells in next generation array
                       nextgenArray[c][d] = "-";
                     }//end else if
                   }//end else if

           //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
                   else if(neighbors == 3){
                     if(numberArray[c][d] == 1){
                         nextnumberArray[c][d] = 1;
                         //store cells in next generation array
                         nextgenArray[c][d] = "X";
                       }//end if
                     }else if(numberArray[c][d] == 0){
                         nextnumberArray[c][d] = 1;
                         //store cells in next generation array
                         nextgenArray[c][d] = "X";
                       }//end else if

           //if there's more than 4 neighbor,overpopulation, cell die
                     else if(neighbors >= 4){
                        nextnumberArray[c][d] = 0;
                        //store cells in next generation array
                        nextgenArray[c][d] = "-";
                      }
      }
      }

      for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
          if (nextnumberArray[i][j] == 1){
            //convert 1 back to X, 0 back to -
            OutputFile << "X";
          }else{
            OutputFile << "-";
          }
        }
        OutputFile << endl;
      }



                }// end of for loop
              }

              }
              InputFile.close();

        }
        else {
          cerr << "not a valid mode" << endl;
          exit(1);
       }


    //situation for random assignment
  }else if (answer=="no"){
    cout << "random assignment" << endl;
    //prompt for row and column and density of world
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
        // get a random number to compare with density
       randomNumber = ((double)rand()/(double)RAND_MAX);
       //generate cells according to density to occupy blocks in array
       if (randomNumber<density)
       {
         //generate cells
         CellArrayRandom[j][i] = "X";
       } else{
         //block is empty
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
//classic mode
    if (mode=="classic")
    {
      //prompt for pause or output to a file
      cout << "enter yes for pause between generations, enter no for output to a file" << endl;
      cin >> choice;

       if (choice=="yes")
       {
         //pause between generations
         cout << "pausing between generations... " << endl;
         cout << "classic mode" << endl;
         //initialize variables
         int Rowrandom = i;
         int Columnrandom = j;
         int numberArrayRandom[Rowrandom][Columnrandom];
         int nextgenRandom[Rowrandom][Columnrandom];
//loop 1000 times
        for (int k=0; k<1000; ++k){
          cout << "Generation # " << k << endl;
           cout << endl;
         for(int e=0; e<Rowrandom; ++e){
           for(int c=0; c<Columnrandom; ++c){
             if(CellArrayRandom[i][j] == "X"){
               //convert X to 1, - to 0
               numberArrayRandom[i][j] = 1;
             }//end if
             else if(CellArrayRandom[i][j] == "-"){
               numberArrayRandom[i][j] = 0;
             }//end else if
           }//end for
         }//end for

         for(int e=0; e<Rowrandom; ++e){
           for(int c=0; c<Columnrandom; ++c){
             //calculate the number of neighbors around cell
             neighborsRandom = numberArrayRandom[Rowrandom-1][Columnrandom-1] + numberArrayRandom[Rowrandom-1][Columnrandom] + numberArrayRandom[Rowrandom-1][Columnrandom+1] + numberArrayRandom[Rowrandom][Columnrandom+1] + numberArrayRandom[Rowrandom+1][Columnrandom-1] + numberArrayRandom[Rowrandom+1][Columnrandom]
             + numberArrayRandom[Rowrandom+1][Columnrandom-1] + numberArrayRandom[Rowrandom][Columnrandom-1];
             //if there's only 1 cell, empty for the next generation
             if(neighborsRandom <=1){
               nextgenRandom[i][j] = 0;
               //store cells in next generation array
               cellArrayRandomnew[i][j] = "-";
             }//end if
             //if there's 2 neighbor, next generation cells live on, if empty, still empty
             else if(neighborsRandom == 2){
               if (numberArrayRandom[i][j] == 1){
                  nextgenRandom[i][j] = 1;
                  //store cells in next generation array
                  cellArrayRandomnew[i][j] = "X";
               }//end if
               else if(numberArrayRandom[i][j] == 0){
                 nextgenRandom[i][j] = 0;
                 //store cells in next generation array
                 cellArrayRandomnew[i][j] = "-";
               }//else if
             }//end else if
    //if there's 3 neighbor, next generation cells live on, if empty, generate a new cell
            else if(neighborsRandom == 3){
              if (numberArrayRandom[i][j] == 1){
                 nextgenRandom[i][j] = 1;
                 //store cells in next generation array
                 cellArrayRandomnew[i][j] = "X";
              }//end if
              else if(numberArrayRandom[i][j] == 0){
                nextgenRandom[i][j] = 1;
                //store cells in next generation array
                cellArrayRandomnew[i][j] = "x";
              }//else if
            }//end else if
             else if(neighborsRandom >= 4){
               nextgenRandom[i][j] = 0;
               //store cells in next generation array
               cellArrayRandomnew[i][j] = "-";
             }//end else if
           }//end for
         }//end for

         for(int g=0; g<row; ++g){
           for(int h=0; h<column; ++h){
             //convert 1 back to X, 0 back to -
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
       else if (choice=="no")
       {
         //output everything to a file
         ofstream OutputFile;
         cout << "enter an output file name" << endl;
         cin >> outputfile;
         //open output file
         OutputFile.open(outputfile);
         cout << "outputting to file...." << endl;

     cout << "classic mode" << endl;
     //initialize variables
     int Rowrandom = i;
     int Columnrandom = j;
     int numberArrayRandom[Rowrandom][Columnrandom];
     int nextgenRandom[Rowrandom][Columnrandom];
//loop 1000 times
    for (int k=0; k<1000; ++k){
      OutputFile << "Generation # " << k << endl;
       OutputFile << endl;
     for(int e=0; e<Rowrandom; ++e){
       for(int c=0; c<Columnrandom; ++c){
         if(CellArrayRandom[i][j] == "X"){
           //convert x to 1, - to 0
           numberArrayRandom[i][j] = 1;
         }//end if
         else if(CellArrayRandom[i][j] == "-"){
           numberArrayRandom[i][j] = 0;
         }//end else if
       }//end for
     }//end for

     for(int e=0; e<Rowrandom; ++e){
       for(int c=0; c<Columnrandom; ++c){
         //add the number of neighbors around cell
         neighborsRandom = numberArrayRandom[Rowrandom-1][Columnrandom-1] + numberArrayRandom[Rowrandom-1][Columnrandom] + numberArrayRandom[Rowrandom-1][Columnrandom+1] + numberArrayRandom[Rowrandom][Columnrandom+1] + numberArrayRandom[Rowrandom+1][Columnrandom-1] + numberArrayRandom[Rowrandom+1][Columnrandom]
         + numberArrayRandom[Rowrandom+1][Columnrandom-1] + numberArrayRandom[Rowrandom][Columnrandom-1];
         //if there's only 1 cell, empty for the next generation
         if(neighborsRandom <=1){
           nextgenRandom[i][j] = 0;
           //store cells in next generation array
           cellArrayRandomnew[i][j] = "-";
         }//end if
         //if there's 2 neighbor, next generation cells live on, if empty, still empty
         else if(neighborsRandom == 2){
           if (numberArrayRandom[i][j] == 1){
              nextgenRandom[i][j] = 1;
              //store cells in next generation array
              cellArrayRandomnew[i][j] = "X";
           }//end if
           else if(numberArrayRandom[i][j] == 0){
             nextgenRandom[i][j] = 0;
             //store cells in next generation array
             cellArrayRandomnew[i][j] = "-";
           }//else if
         }//end else if
//if there's 3 neighbor, next generation cells live on, if empty, generate a new cell
        else if(neighborsRandom == 3){
          if (numberArrayRandom[i][j] == 1){
             nextgenRandom[i][j] = 1;
             //store cells in next generation array
             cellArrayRandomnew[i][j] = "X";
          }//end if
          else if(numberArrayRandom[i][j] == 0){
            nextgenRandom[i][j] = 1;
            //store cells in next generation array
            cellArrayRandomnew[i][j] = "x";
          }//else if
        }//end else if
        //overpopulation, cell die
         else if(neighborsRandom >= 4){
           nextgenRandom[i][j] = 0;
           //store cells in next generation array
           cellArrayRandomnew[i][j] = "-";
         }//end else if
       }//end for
     }//end for

     for(int g=0; g<row; ++g){
       for(int h=0; h<column; ++h){
         if(nextgenRandom[g][h] ==1){
           //convert 1 back to x, 0 back to -
           OutputFile << "X";
         }//end if
         else{
           OutputFile << "-";
         }//end else
       }//end for
       OutputFile << endl;
     }//end for
      cout << "Generation # " << k << endl;
    }
  }

}// end of class mode loop

  //donut mode under random assignment
    else if (mode=="doughnut")
    {
     cout << "doughnutmode" << endl;
     cout << "enter yes for pause between generations, enter no for outputing to a file" << endl;
     cin >> choice;
     if (choice=="yes")
     {
       //pause between generations
       cout << "pause between generations" << endl;
//initialize variables
       int neighborsrandomDoughnut = 0;
       int RowrandomDoughnut=i;
       int ColumnrandomDoughnut=j;
       string nextgenRandomDoughnut[RowrandomDoughnut][ColumnrandomDoughnut];
       int nextnumberArrayRandomDoughnut[RowrandomDoughnut][ColumnrandomDoughnut];
       int numberArrayRandomDoughnut[RowrandomDoughnut][ColumnrandomDoughnut];
       // in case row - 1 = -1
       int protectedrRandomDoughnut;
       int protectedcRandomDoughnut;
//loop 1000 times
     for(int k = 0; k <= 1000; k++){
       cout << endl;
       cout << "Generation # " << k << endl;
       for(int c = 0; c < RowrandomDoughnut; ++c){
         for(int d = 0; d < ColumnrandomDoughnut; ++d){
           //convert x to 1, - to 0
           if (CellArrayRandom[c][d] == "X"){
             numberArrayRandomDoughnut[c][d] = 1;
          } else if(CellArrayRandom[c][d] == "-"){
            numberArrayRandomDoughnut[c][d] = 0;
          }
         }
       }

//cells are at edges
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
//add up the amount of neighbors around cell
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
           //there's one neighbor, empty cell
             if(neighborsrandomDoughnut < 2){
                nextnumberArrayRandomDoughnut[c][d] = 0;
                //store cells in next generation array
                nextgenRandomDoughnut[c][d] = "-";
              }//end if

    ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
            else if(neighborsrandomDoughnut == 2){
              if(numberArrayRandomDoughnut[c][d] == 1){
                nextnumberArrayRandomDoughnut[c][d] = 1;
                //store cells in next generation array
                nextgenRandomDoughnut[c][d] = "X";
              }//end if
              else if(numberArrayRandomDoughnut[c][d] == 0){
                nextnumberArrayRandomDoughnut[c][d] = 0;
                //store cells in next generation array
                nextgenRandomDoughnut[c][d] = "-";
              }//end else if
            }//end else if

    //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
            else if(neighborsrandomDoughnut == 3){
              if(numberArrayRandomDoughnut[c][d] == 1){
                  nextnumberArrayRandomDoughnut[c][d] = 1;
                  //store cells in next generation array
                  nextgenRandomDoughnut[c][d] = "X";
                }//end if
              }else if(numberArrayRandomDoughnut[c][d] == 0){
                  nextnumberArrayRandomDoughnut[c][d] = 1;
                  //store cells in next generation array
                  nextgenRandomDoughnut[c][d] = "X";
                }//end else if

    //if there's more than 4 neighbor,overpopulation, cell die
              else if(neighborsrandomDoughnut >= 4){
                 nextnumberArrayRandomDoughnut[c][d] = 0;
                 //store cells in next generation array
                 nextgenRandomDoughnut[c][d] = "-";
               }
  }
  }

  for(int i = 0; i < row; ++i){
  for(int j = 0; j < column; ++j){
   if (nextnumberArrayRandomDoughnut[i][j] == 1){
     //convert 1 back to x, 0 back to -
     cout << "X";
   }else{
     cout << "-";
   }
  }
  cout << endl;
  }
  }
     }
     else if (choice=="no")
     {
       //output to a file
       ofstream OutputFile;
       cout << "enter an output file name" << endl;
       cin >> outputfile;
       //open output file
       OutputFile.open(outputfile);
       cout << "outputting to file..." << endl;

//initialize variables
     int neighborsrandomDoughnut = 0;
     int RowrandomDoughnut=i;
     int ColumnrandomDoughnut=j;
     string nextgenRandomDoughnut[RowrandomDoughnut][ColumnrandomDoughnut];
     int nextnumberArrayRandomDoughnut[RowrandomDoughnut][ColumnrandomDoughnut];
     int numberArrayRandomDoughnut[RowrandomDoughnut][ColumnrandomDoughnut];
     // in case row - 1 = -1
     int protectedrRandomDoughnut;
     int protectedcRandomDoughnut;
//loop 1000 times
   for(int k = 0; k <= 1000; k++){
     OutputFile << endl;
     OutputFile << "Generation # " << k << endl;
     for(int c = 0; c < RowrandomDoughnut; ++c){
       for(int d = 0; d < ColumnrandomDoughnut; ++d){
         if (CellArrayRandom[c][d] == "X"){
           //convert x to 1, - to 0
           numberArrayRandomDoughnut[c][d] = 1;
        } else if(CellArrayRandom[c][d] == "-"){
          numberArrayRandomDoughnut[c][d] = 0;
        }
       }
     }

//cells is at edges
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
//add up the number of neighbors around cells
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
         //one neighbor, empty cell
           if(neighborsrandomDoughnut < 2){
              nextnumberArrayRandomDoughnut[c][d] = 0;
              //store cells in next generation array
              nextgenRandomDoughnut[c][d] = "-";
            }//end if

  ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
          else if(neighborsrandomDoughnut == 2){
            if(numberArrayRandomDoughnut[c][d] == 1){
              nextnumberArrayRandomDoughnut[c][d] = 1;
              //store cells in next generation array
              nextgenRandomDoughnut[c][d] = "X";
            }//end if
            else if(numberArrayRandomDoughnut[c][d] == 0){
              nextnumberArrayRandomDoughnut[c][d] = 0;
              //store cells in next generation array
              nextgenRandomDoughnut[c][d] = "-";
            }//end else if
          }//end else if

  //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
          else if(neighborsrandomDoughnut == 3){
            if(numberArrayRandomDoughnut[c][d] == 1){
                nextnumberArrayRandomDoughnut[c][d] = 1;
                //store cells in next generation array
                nextgenRandomDoughnut[c][d] = "X";
              }//end if
            }else if(numberArrayRandomDoughnut[c][d] == 0){
                nextnumberArrayRandomDoughnut[c][d] = 1;
                //store cells in next generation array
                nextgenRandomDoughnut[c][d] = "X";
              }//end else if

  //if there's more than 4 neighbor,overpopulation, cell die
            else if(neighborsrandomDoughnut >= 4){
               nextnumberArrayRandomDoughnut[c][d] = 0;
               //store cells in next generation array
               nextgenRandomDoughnut[c][d] = "-";
             }
}
}

for(int i = 0; i < row; ++i){
for(int j = 0; j < column; ++j){
  //convert 1 back to x, 0 back to -
 if (nextnumberArrayRandomDoughnut[i][j] == 1){
   OutputFile << "X";
 }else{
   OutputFile << "-";
 }
}
OutputFile << endl;
}

}
OutputFile.close();

}

    }
    //mirror mode
    else if (mode=="mirror")
    {
     cout << "mirror mode" << endl;
     //prompt for pause between generations or output to a file
     cout << "enter yes for pause between generations, enter no for outputing to a file" << endl;
     cin >> choice;
     if (choice=="yes")
     {
       // pause between generation
       cout << "pause between generations" << endl;
//initialize variables
            int neighborsrandomMirror = 0;
            int RowrandomMirror=i;
            int ColumnrandomMirror=j;
            string nextgenRandomMirror[RowrandomMirror][ColumnrandomMirror];
            int nextnumberArrayRandomMirror[RowrandomMirror][ColumnrandomMirror];
            int numberArrayRandomMirror[RowrandomMirror][ColumnrandomMirror];
            int RplusRandom;
            int RminusRandom;
            int CplusRandom;
            int CminusRandom;
            //print out 1000 generations
            for(int k = 0; k <= 1000; k++){
              cout << endl;
              cout << "Generation # " << k << endl;
              for(int c = 0; c < RowrandomMirror; ++c){
                for(int d = 0; d < ColumnrandomMirror; ++d){
                  //convert X and - to 1 and 0
                  if (CellArrayRandom[c][d] == "X"){
                    numberArrayRandomMirror[c][d] = 1;
                 } else if(CellArrayRandom[c][d] == "-"){
                   numberArrayRandomMirror[c][d] = 0;
                 }
                }
              }
//mirror reflection on cells
              if (RowrandomMirror+1 == row) {
                  RplusRandom = row;
                } else {
                  RplusRandom = RowrandomMirror+1;
                }
                //cells are at edges
                if (RowrandomMirror-1 == -1) {
                    RminusRandom = row;
                  } else {
                    RminusRandom = RowrandomMirror-1;
                }if (ColumnrandomMirror+1 == column) {
                    CplusRandom = column;
                } else {
                    CplusRandom = ColumnrandomMirror+1;
                }if (ColumnrandomMirror-1 == -1) {
                    CminusRandom = column;
                  } else {
                    CminusRandom = ColumnrandomMirror-1;
                  }

//add up the number of neighbors around cell
                  if(CellArrayRandom[RowrandomMirror][CplusRandom] == "X"){
                    neighborsrandomMirror++;
                  }
                  if(CellArrayRandom[RowrandomMirror][CminusRandom] == "X"){
                    neighborsrandomMirror++;
                  }
                  if(CellArrayRandom[RminusRandom][CminusRandom] == "X"){
                    neighborsrandomMirror++;
                  }
                  if(CellArrayRandom[RminusRandom][CplusRandom] == "X"){
                    neighborsrandomMirror++;
                  }
                  if(CellArrayRandom[RminusRandom][CplusRandom] == "X"){
                    neighborsrandomMirror++;
                  }
                  if(CellArrayRandom[RplusRandom][CplusRandom] == "X"){
                    neighborsrandomMirror++;
                  }
                  if(CellArrayRandom[RplusRandom][CminusRandom] == "X"){
                    neighborsrandomMirror++;
                  }
                  if(CellArrayRandom[RplusRandom][CplusRandom] == "X"){
                    neighborsrandomMirror++;
                  }

                  for(int c = 0; c < RowrandomMirror; ++c){
                    for(int d = 0; d < ColumnrandomMirror; ++d){
                    //one or less cell around, empty cell
                      if(neighborsrandomMirror < 2){
                         nextnumberArrayRandomMirror[c][d] = 0;
                         //store cells in next generation array
                         nextgenRandomMirror[c][d] = "-";
                       }//end if


               ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
                     else if(neighborsrandomMirror == 2){
                        if(numberArrayRandomMirror[c][d] == 1){
                           nextnumberArrayRandomMirror[c][d] = 1;
                           //store cells in next generation array
                           nextgenRandomMirror[c][d] = "X";
                       }//end if
                         else if(numberArrayRandomMirror[c][d] == 0){
                           nextnumberArrayRandomMirror[c][d] = 0;
                           //store cells in next generation array
                           nextgenRandomMirror[c][d] = "-";
                        }//end else if
                        }//end else if

           //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
                     else if(neighborsrandomMirror == 3){
                         if(numberArrayRandomMirror[c][d] == 1){
                             nextnumberArrayRandomMirror[c][d] = 1;
                             //store cells in next generation array
                             nextgenRandomMirror[c][d] = "X";
                        }//end if
                      }else if(numberArrayRandomMirror[c][d] == 0){
                            nextnumberArrayRandomMirror[c][d] = 1;
                            //store cells in next generation array
                            nextgenRandomMirror[c][d] = "X";
                         }//end else if

            //if there's more than 4 neighbor,overpopulation, cell die
                           else if(neighborsrandomMirror >= 4){
                             nextnumberArrayRandomMirror[c][d] = 0;
                             //store cells in next generation array
                             nextgenRandomMirror[c][d] = "-";
                         }
                       }
                       }

                         for(int i = 0; i < row; ++i){
                           for(int j = 0; j < column; ++j){
                               if (nextnumberArrayRandomMirror[i][j] == 1){
                                 //convert 1 back to x, 0 back to -
                                   cout << "X";
                             }else{
                                   cout << "-";
                                 }
                               }
                               cout << endl;
                             }
                           }

     }
     else if (choice=="no")
     {
       //output to a file
       ofstream OutputFile;
       cout << "enter an output file name" << endl;
       cin >> outputfile;
       //open output file
       OutputFile.open(outputfile);
       cout << "outputting to file..." << endl;
//initialize variables
     int neighborsrandomMirror = 0;
     int RowrandomMirror=i;
     int ColumnrandomMirror=j;
     string nextgenRandomMirror[RowrandomMirror][ColumnrandomMirror];
     int nextnumberArrayRandomMirror[RowrandomMirror][ColumnrandomMirror];
     int numberArrayRandomMirror[RowrandomMirror][ColumnrandomMirror];
     int RplusRandom;
     int RminusRandom;
     int CplusRandom;
     int CminusRandom;
     //print out 1000 generations
     for(int k = 0; k <= 1000; k++){
       OutputFile << endl;
       OutputFile << "Generation # " << k << endl;
       for(int c = 0; c < RowrandomMirror; ++c){
         for(int d = 0; d < ColumnrandomMirror; ++d){
           //convert X and - to 1 and 0
           if (CellArrayRandom[c][d] == "X"){
             numberArrayRandomMirror[c][d] = 1;
          } else if(CellArrayRandom[c][d] == "-"){
            numberArrayRandomMirror[c][d] = 0;
          }
         }
       }
//mirror reflections on cells
       if (RowrandomMirror+1 == row) {
           RplusRandom = row;
         } else {
           RplusRandom = RowrandomMirror+1;
         }
         //cells at edges
         if (RowrandomMirror-1 == -1) {
             RminusRandom = row;
           } else {
             RminusRandom = RowrandomMirror-1;
         }if (ColumnrandomMirror+1 == column) {
             CplusRandom = column;
         } else {
             CplusRandom = ColumnrandomMirror+1;
         }if (ColumnrandomMirror-1 == -1) {
             CminusRandom = column;
           } else {
             CminusRandom = ColumnrandomMirror-1;
           }

//add the number of neighbors around cells
           if(CellArrayRandom[RowrandomMirror][CplusRandom] == "X"){
             neighborsrandomMirror++;
           }
           if(CellArrayRandom[RowrandomMirror][CminusRandom] == "X"){
             neighborsrandomMirror++;
           }
           if(CellArrayRandom[RminusRandom][CminusRandom] == "X"){
             neighborsrandomMirror++;
           }
           if(CellArrayRandom[RminusRandom][CplusRandom] == "X"){
             neighborsrandomMirror++;
           }
           if(CellArrayRandom[RminusRandom][CplusRandom] == "X"){
             neighborsrandomMirror++;
           }
           if(CellArrayRandom[RplusRandom][CplusRandom] == "X"){
             neighborsrandomMirror++;
           }
           if(CellArrayRandom[RplusRandom][CminusRandom] == "X"){
             neighborsrandomMirror++;
           }
           if(CellArrayRandom[RplusRandom][CplusRandom] == "X"){
             neighborsrandomMirror++;
           }

           for(int c = 0; c < RowrandomMirror; ++c){
             for(int d = 0; d < ColumnrandomMirror; ++d){
             //there's one cell or less around, empty cell
               if(neighborsrandomMirror < 2){
                  nextnumberArrayRandomMirror[c][d] = 0;
                  //store cells in next generation array
                  nextgenRandomMirror[c][d] = "-";
                }//end if


        ////if there's 2 neighbor, next generation cell lives on, if empty, still empty
              else if(neighborsrandomMirror == 2){
                 if(numberArrayRandomMirror[c][d] == 1){
                    nextnumberArrayRandomMirror[c][d] = 1;
                    //store cells in next generation array
                    nextgenRandomMirror[c][d] = "X";
                }//end if
                  else if(numberArrayRandomMirror[c][d] == 0){
                    nextnumberArrayRandomMirror[c][d] = 0;
                    //store cells in next generation array
                    nextgenRandomMirror[c][d] = "-";
                 }//end else if
                 }//end else if

    //if there's 3 neighbor, next generation cell lives on, if empty, generate a new cell
              else if(neighborsrandomMirror == 3){
                  if(numberArrayRandomMirror[c][d] == 1){
                      nextnumberArrayRandomMirror[c][d] = 1;
                      //store cells in next generation array
                      nextgenRandomMirror[c][d] = "X";
                 }//end if
               }else if(numberArrayRandomMirror[c][d] == 0){
                     nextnumberArrayRandomMirror[c][d] = 1;
                     //store cells in next generation array
                     nextgenRandomMirror[c][d] = "X";
                  }//end else if

     //if there's more than 4 neighbor,overpopulation, cell die
                    else if(neighborsrandomMirror >= 4){
                      nextnumberArrayRandomMirror[c][d] = 0;
                      //store cells in next generation array
                      nextgenRandomMirror[c][d] = "-";
                  }
                }
                }

                  for(int i = 0; i < row; ++i){
                    for(int j = 0; j < column; ++j){
                        if (nextnumberArrayRandomMirror[i][j] == 1){
                          //convert 1 back to x, 0 back to -
                            OutputFile << "X";
                      }else{
                            OutputFile << "-";
                          }
                        }
                        OutputFile << endl;
                      }
                    }
    }//end print 1000 times for
  }else
    {
      cerr << "not a valid mode" << endl;
      exit(1);
    }


 }

  return 0;

}
