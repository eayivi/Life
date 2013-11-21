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
    
      vector< vector<T*> > board; 


    public: 
        Life();

        Life (int num_row, int num_col) : row_size(num_row), col_size (num_col) {
            
        }

        void replicateBoard(istream& in){
            char currentCell;
            for(int i = 0; i < row_size; i++){ 
                vector<T*> temp;  
                for(int j = 0; j < col_size; j++){
                  in >> currentCell;

                  //AbstractCell* parent;
                  //If Conway Cell '.' or '*'
                  if(currentCell == '.' || currentCell == '*'){
                    T conway(currentCell);
                   // *parent = conway;
                    temp.push_back(&conway);
                  }
                  //If Fredkin Cell '-', '+', and 0-9
                  else if((currentCell == '-') || (currentCell =='+') || (currentCell >= '0' && currentCell <= '9')){
                    T frankin(currentCell);
                   // *parent = frankin;
                    temp.push_back(&frankin);

                  } else {
                    cout << "!!!!!!!!!!!!!!Wrong Input format!!!!!!!!!!" << endl;
                  }

                  //temp.push_back(parent);
                }
                board.push_back(temp);
            }
    
       }

       void update_neighbors () {
            for(int i = 0; i < row_size; i++){ 
                for(int j = 0; j < col_size; j++){
                    // if (board[i][j].get_liveness())
                    //     cout << "is alive!" << endl;
                    board[i][j]->neigbhorcount (5);

                }

            }        

       }

        void printBoard (std::ostream& w) {

            for (int i = 0; i < row_size; ++i){
                for (int j= 0; j <col_size ; ++j) {
                    board[i][j]->print_cell(w); 
                }
                w << endl;
            }
       }


 };



 #endif // Life_h