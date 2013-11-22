// --------
// ConwayCell.h
// --------

// --------
// includes
// --------
#ifndef ConwayCell_h
#define ConwayCell_h

#include <iostream> // istream, ostream
#include <utility>  // !=
#include <iostream> // istream, ostream
#include "AbstractCell.h"

using namespace std;
class ConwayCell : public AbstractCell {

    private:
 

    protected:

    public:
        ConwayCell () :   AbstractCell () {
            //_isAlive = true;
        }

        ConwayCell (bool alive, int neighbors = 0) :   AbstractCell (alive, neighbors) {
            //_isAlive = true;
        }


        void set_diag_neighbors(int x) {
            neighbors_cnt += x;
        }
        
        void print_cell (std::ostream& w)  {
            if (_isAlive)
                w << '*';
            else
                w << '.';
        }

        void evolve() {

            if (!_isAlive and neighbors_cnt == 3) {
                _isAlive = true;
            } else if (_isAlive and (neighbors_cnt < 2 or neighbors_cnt >3) ) {
                _isAlive = false;
            }
            neighbors_cnt = 0;
        }

        bool mutate () {
          return false;     // Conway Cells never mutate
        }




/*
        ConwayCell (const ConwayCell& that) :
                AbstractCell (that),
                _r            (that._r)
            {}

        virtual ~ConwayCell ()
            {}

        ConwayCell& operator = (const ConwayCell& that) {
            AbstractCell::operator=(that);
            _r = that._r;
            return *this;}
*/


        ConwayCell* clone () const {
            return new ConwayCell(*this);}

        };

 #endif // ConwayCell_h
