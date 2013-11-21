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


template <typename T>
class Life{

    private:
      int row_size; 
      int col_size;  
    
      vector< vector<T> > board; 


    public: 
        Life();

        Life (int num_row, int num_col) : row_size(num_row), col_size (num_col) {
            board.resize(num_row, vector<T>(num_col));
        }

        void replicateBoard(istream& in){
            char currentCell;
            for(int i = 0; i < row_size; i++){ 
                 
                for(int j = 0; j < col_size; j++){
                  in >> currentCell;

                  if(currentCell == '.' || currentCell == '-'){
                    board[i][j].flipLiveStatus();
                  }

                 
                
                }
                
            }
    
       }

       void update_neighbors () {
            for(int i = 0; i < row_size; i++){ 
                for(int j = 0; j < col_size; j++){
                    // if (board[i][j].get_liveness())
                    //     cout << "is alive!" << endl;
                    // board[i][j]->neigbhorcount (5);

                }

            }        

       }

        void printBoard (std::ostream& w) {

            for (int i = 0; i < row_size; ++i){
                for (int j= 0; j <col_size ; ++j) {
                    board[i][j].print_cell(w); 
                }
                w << endl;
            }
       }


 };



 #endif // Life_h