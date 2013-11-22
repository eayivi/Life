 // --------
// FredkinCell.c++
// --------

#include "FredkinCell.h"

FredkinCell::FredkinCell () : AbstractCell (), age(0) { }

void FredkinCell::set_diag_neighbors(int x) {}



void FredkinCell::print_cell (std::ostream& w)  {
	    if (_isAlive) {
	       if (age < 10) {
	            w << age;
	       } else 
	            w << "+";
	    }
	    else
	        w << '-';
	}



void FredkinCell::evolve() {

	    if (!_isAlive and (neighbors_cnt == 3 or neighbors_cnt ==1) )  {
	        _isAlive = true;
	    } else if (_isAlive and ( neighbors_cnt == 0 or neighbors_cnt == 2 or neighbors_cnt ==4) ) {
	        _isAlive = false;
	    } else if (_isAlive)
	        age++;
	    neighbors_cnt = 0;
	}

bool FredkinCell::mutate() {
          return (age ==2);
        }

FredkinCell * FredkinCell::clone () const {
            return new FredkinCell(*this);
        }