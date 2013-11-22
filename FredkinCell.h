  // --------
  // FredkinCell.h
  // --------
#ifndef FredkinCell_h
#define FredkinCell_h

#include "AbstractCell.h"

class FredkinCell : public AbstractCell {

    private:
        int age;


    public:
        FredkinCell ()  ;
        
        void set_diag_neighbors(int) ;

        void print_cell (std::ostream& )  ;

        void evolve() ;

        bool mutate () ;


        FredkinCell* clone () const ;
};
#endif // FredkinCell_h
  
