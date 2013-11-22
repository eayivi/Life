  // --------
  // FredkinCell.h
  // --------
#ifndef FredkinCell_h
#define FredkinCell_h

#include "AbstractCell.h"


// ------
// FredkinCell
// ------

/**
 * Fredkin Cell is a type of cell that inherits from Abstract cell
 * 
 */
class FredkinCell : public AbstractCell {

    private:
        int age;  /**<cell age */


    public:
         /** Fredkin Cell 
           */
        FredkinCell ()  ;
        
        // -----------
        // set_diag_neighbors
        // -----------
        
        /** 
          * Number of neighbor diagonals if any
          */
        void set_diag_neighbors(int) ;

        // -----------
        // print_cell
        // -----------
        
        /** 
          * Print current Cell
          */
        void print_cell (std::ostream& )  ;

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
          */
        bool mutate () ;

        // -----------
        // clone
        // -----------
        
        /** 
          * Replicate
          */
        FredkinCell* clone () const ;
};
#endif // FredkinCell_h
  
