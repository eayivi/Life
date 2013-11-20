// --------
// Life.h
// --------
#ifndef Life_h
#define Life_h

// --------
// includes
// --------

#include <iostream>
#include <vector>
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "AbstractCell.h"
#include "Cell.h"

using namespace std;

template <typename T>
class Life{

    private:
      int row_size; 
      int col_size;  
     
     public:    
      vector< vector<T> > board; 

    public: 
        Life(){

        }

        void readBoardSize(istream& in){
          in >> row_size;
          in >> col_size;
          cout << "Board size: " << row_size << " x " << col_size <<endl;
        }


        void replicateBoard(istream& in){

          char currentCell;
          for(int i = 0; i < row_size; i++){
            for(int j = 0; j < col_size; j++){
              in >> currentCell;

              bool alive = true;
              if(currentCell == '.' || currentCell == '-'){
                alive = false;
              }

              AbstractCell* thisCell;
              //If Conway Cell '.' or '*'
              if(currentCell == '.' || currentCell == '*'){
                ConwayCell conway(alive, i, j);
                // board[i][j] = Cell 
                thisCell = &conway;
              }
              //If Fredkin Cell '-', '+', and 0-9
              else if((currentCell == '-') || (currentCell =='+') || (currentCell >= '0' && currentCell <= '9')){
                // FredkinCell frankin(alive,i,j);
                // thisCell = &frankin;
              } else {
                cout << "!!!!!!!!!!!!!!Wrong Input format!!!!!!!!!!" << endl;
              }

              Cell cell(thisCell);
              board[i][j] = cell;
            }
          }

        }


 };



 #endif // Life_h