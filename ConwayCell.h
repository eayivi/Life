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
class ConwayCell : public AbstractCell {

    public:
        ConwayCell () ;

        ConwayCell (bool alive, int neighbors = 0) ;


        void set_diag_neighbors(int x);
        
        void print_cell (std::ostream& ) ;

        void evolve() ;

        bool mutate () ;

        ConwayCell* clone () const ;

        };

 #endif // ConwayCell_h
