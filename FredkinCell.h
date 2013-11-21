// --------
// FredkinCell.h
// --------
#ifndef FredkinCell_h
#define FredkinCell_h

#include <iostream> // istream, ostream
#include <utility>  // !=
#include <iostream> // istream, ostream
#include "AbstractCell.h"

using namespace std;
class FredkinCell : public AbstractCell {

    private:
        int age;


    public:
        FredkinCell () :   AbstractCell () {
           age = 0;
        }
        
        void set_diag_neighbors(int x) {
            // pass
        }

        void print_cell (std::ostream& w)  {
            if (_isAlive) {
               if (age < 10) {
                    w << age;
               } else 
                    w << "+";
            }
            else
                w << '-';
        }

        void evolve() {

            if (!_isAlive and (neighbors_cnt == 3 or neighbors_cnt ==1) )  {
                _isAlive = true;
            } else if (_isAlive and neighbors_cnt < 2 and neighbors_cnt >3) {
                _isAlive = false;
            }
            age++;
            neighbors_cnt = 0;
        }

        // ConwayCell* clone () const {
        //     return new ConwayCell(*this);}
};
#endif // FredkinCell_h
  