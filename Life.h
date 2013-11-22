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

// ------
// Class Life 
// ------

/**
  * Class Life template <typename T>
  */
template <typename T>
class Life{

    private:
      int row_size; /**< # of rows in the grid */
      int col_size; /**< # of columns in the grid */
      int generation; /**< current generation */
      int population;  /**< current population */
    
      vector< vector<T> > board; /**< Grid of T objects*/


    public: 
        /** 
          * Default Life costructor
          */
        Life();

         /** 
          *@param Number of rows
          *@param Number of columns 
          *@param Generation 
          *@param Population
          */
        Life (int num_row, int num_col) : row_size(num_row), col_size (num_col), generation(0), population(0) {
            board.resize(num_row+2, vector<T>(num_col+2));
        }

         // -----------
        // giveEveryoneOneTurn
        // -----------
        /** 
          *  Generate a boar to simulate Life from a text file
          */
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

        // -----------
        // count_neighbors
        // -----------
        /** 
          * Update number count of neighbors in the current generation
          */
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

        // -----------
        // printBoard
        // -----------
        /** 
          * Print board of the current generation
          */
        void printBoard (std::ostream& w) {
            w << "Generation = " << generation ;
            w << ", Population = " << population << endl;

            for (int i = 0; i < row_size+2; ++i){
                for (int j= 0; j <col_size+2 ; ++j) {

                    // Turn on Moat
                    //if (i ==0 or i == row_size+1 or j == 0 or j == col_size+1) {
                    //    w << '@';
                    //    continue;
                    //}
                    // end Moat
                    board[i][j].print_cell(w); 
                }
                w << endl;
            }
            w << endl;
       }

        // -----------
        // printneighbor_count
        // -----------
        /** 
          * Print count of neighbors
          */
       void printneighbor_count (std::ostream& w) {
            for (int i = 0; i < row_size+2; ++i){
                for (int j= 0; j <col_size+2 ; ++j) {
                    if (board[i][j].neighbors_cnt != 0)
                      cout << " position " << i << "," << j << " has " << board[i][j].neighbors_cnt << " neighbors" <<endl ;
                }
            }
       }

        // -----------
        // simulateNth
        // -----------
        /**  Simulate # of life generations 
          * @param number of moves to simulate 
          * @param number of board simulations to print 
          */
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
                    population++;
                  }
                }
            }
            generation++;
          }

       }};

 #endif // Life_h
