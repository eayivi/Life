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

class Cell : Handle<AbstractCell> {

    public:

        Cell () : Handle( new FredkinCell()) {}

        Cell(AbstractCell* p) : 
            Handle<AbstractCell> (p){};


        void print_cell(std::ostream& w) {
            get()->print_cell(w);
        }

        void cometolife(){
            get()->cometolife();
        }
    
        bool get_liveness() {
            return get()->get_liveness();
        }

        void set_straight_neighbors (int x) {
           get()->set_straight_neighbors(x);
        };

        void set_diag_neighbors(int x) {
            get()->set_diag_neighbors(x);    
        }

        void evolve() {
            get()->evolve();

            if (get()->mutate()) {
              bool isAlive = get()->get_liveness();
              AbstractCell* ptr = new ConwayCell (isAlive);
              Cell q(ptr);
              swap (q);

            }
        }
};

 #endif // Cell_h 
