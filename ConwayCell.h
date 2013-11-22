// --------
// ConwayCell.h
// --------

// --------
// includes
// --------
#ifndef ConwayCell_h
#define ConwayCell_h

#include "AbstractCell.h"

using namespace std;


// ------
// ConwayCell
// ------

/**
 * ConwayCell Cell is a type of cell that inherits from Abstract cell
 * 
 */
class ConwayCell : public AbstractCell {

    public:
        /** ConwayCell Cell 
           */
        ConwayCell () ;

        /** ConwayCell Cell 
           */
        ConwayCell (bool alive, int neighbors = 0) ;

        // -----------
        // set_diag_neighbors
        // -----------
        
        /** 
          * Number of neighbor diagonals if any
          */
        void set_diag_neighbors(int x);
        
        // -----------
        // print_cell
        // -----------
        
        /** 
          * Print current Cell
          */
        void print_cell (std::ostream& ) ;

        // -----------
        // evolve
        // -----------
        
        /** 
          * Evolve when in a Cell type enviroment
          */
        void evolve() ;

        // -----------
        // mutate
        // -----------
        
        /** 
          * Transform from another cell to this cell
          * 
          */
    
        bool mutate () ;
        
        // -----------
        // clone
        // -----------
        
        /** 
          * Replicate
          */
        ConwayCell* clone () const ;};

 #endif // ConwayCell_h
