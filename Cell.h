// --------
// Cell.h
// --------
#ifndef Cell_h
#define Cell_h

// --------
// includes
// --------
#include "Handle.h"
#include "AbstractCell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"


// ------
// Cell
// ------

/**
 *Cell is a class that is a raper to other cells. When needed to have two types of cells  
 */
class Cell : Handle<AbstractCell> {

    public:
         /** Cell Cell 
           */
        Cell () : Handle( new FredkinCell()) {}

         /** Cell Cell 
           */
        Cell(AbstractCell* p) : 
            Handle<AbstractCell> (p){};

        // -----------
        // print_cell
        // -----------
        
        /** 
          * Print current Cell
          */
        void print_cell(std::ostream& w) {
            get()->print_cell(w);
        }

        // -----------
        // cometolife
        // -----------
        
        /** 
          * Revive Cell
          */
        void cometolife(){
            get()->cometolife();
        }
    
         // -----------
        // get_liveness
        // -----------
        
        /** 
          * Check status 
          */
        bool get_liveness() {
            return get()->get_liveness();
        }

         // -----------
        // set_straight_neighbors
        // -----------
        
        /** 
          * Number of neighors 
          */
        void set_straight_neighbors (int x) {
           get()->set_straight_neighbors(x);
        };

        // -----------
        // set_diag_neighbors
        // -----------
        
        /** 
          *Invoque the right method according to the object type
          */
        void set_diag_neighbors(int x) {
            get()->set_diag_neighbors(x);    
        }

        // -----------
        // evolve
        // -----------
        
        /** 
          * Invoque the right method according to the object type
          */
        void evolve() {
            get()->evolve();

            if (get()->mutate()) {
              bool isAlive = get()->get_liveness();
              AbstractCell* ptr = new ConwayCell (isAlive);
              Cell q(ptr);
              swap (q);

            }
        }};

 #endif // Cell_h 
