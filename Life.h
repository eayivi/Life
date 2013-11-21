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
      int generation;
      int population;  
    
      vector< vector<T> > board; 


    public: 
        Life();

        Life (int num_row, int num_col) : row_size(num_row), col_size (num_col), generation(0), population(0) {
            board.resize(num_row+2, vector<T>(num_col+2));
        }

        void replicateBoard(istream& in){
            char currentCell;
            for(int i = 1; i < row_size+1; i++){                 
                for(int j = 1; j < col_size+1; j++){
                  in >> currentCell;

                  if(currentCell == '*' || currentCell == '+' || (currentCell >= '0' && currentCell <= '9')){
                    board[i][j].cometolife();
                    population ++;
                  }
                }
                
            }
    
       }

       void count_neighbors () {
            //cout << endl << "counting neighbors..." << endl;
            for(int i = 1; i < row_size+1; i++){ 
                for(int j = 1; j < col_size+1; j++){
                    //cout << "in neighbors_cnt" << endl;
                  int count = 0;
                      // count straight neighbors
                  if (board[i-1][j].get_liveness())
                    count++;
                  if (board[i][j+1].get_liveness())
                    count++;
                  if (board[i+1][j].get_liveness())
                    count++;
                  if (board[i][j-1].get_liveness())
                    count++;

                  board[i][j].set_straight_neighbors (count);

                  count = 0;
                      // count diagonal neighbors
                  if (board[i-1][j-1].get_liveness())
                    count++;
                  if (board[i-1][j+1].get_liveness())
                    count++;
                  if (board[i+1][j-1].get_liveness())
                    count++;
                  if (board[i+1][j+1].get_liveness())
                    count++;
                  board[i][j].set_diag_neighbors (count);                                    
                }

            }        

       }

        void printBoard (std::ostream& w) {
            w << "Generation = " << generation ;
            w << ", Population = " << population << endl;

            for (int i = 0; i < row_size+2; ++i){
                for (int j= 0; j <col_size+2 ; ++j) {

                    // Turn on Moat
                    if (i ==0 or i == row_size+1 or j == 0 or j == col_size+1) {
                        w << '@';
                        continue;
                    }
                    board[i][j].print_cell(w); 
                }
                w << endl;
            }
       }

       void printneighbor_count (std::ostream& w) {
            //cout << "printint neighbors" << endl;
            for (int i = 0; i < row_size+2; ++i){
                for (int j= 0; j <col_size+2 ; ++j) {

                    if (board[i][j].neighbors_cnt != 0)
                      cout << " position " << i << "," << j << " has " << board[i][j].neighbors_cnt << " neighbors" <<endl ;
                }
            }
       }

       void simulateNth(int num_moves, int nbr_print =0 ) {

          
          for (int k = 0; k < num_moves; k++) {
            count_neighbors();
            if (nbr_print > 0)
              printBoard(cout);
            nbr_print --;
            population = 0;
            for(int i = 1; i < row_size+1; i++){                 
                for(int j = 1; j < col_size+1; j++){
                  board[i][j].evolve();
                  if (board[i][j].get_liveness()) {
                   // cout << endl << " incrementing population " << endl;
                    population++;
                    //cout << endl << "pop is now " << population;
                  }
                }
            }
            generation++;
          }

       }

 };



 #endif // Life_h