// --------
// ConwayCell.c++
// --------

#include "ConwayCell.h"

ConwayCell::ConwayCell () : AbstractCell () {}

ConwayCell::ConwayCell (bool alive, int neighbors) : AbstractCell (alive, neighbors) {}

void ConwayCell::set_diag_neighbors (int x) {
            neighbors_cnt += x;
        }


void ConwayCell::print_cell (std::ostream& w)  {
            if (_isAlive)
                w << '*';
            else
                w << '.';
        }

void ConwayCell::evolve () {

            if (!_isAlive and neighbors_cnt == 3) {
                _isAlive = true;
            } else if (_isAlive and (neighbors_cnt < 2 or neighbors_cnt >3) ) {
                _isAlive = false;
            }
            neighbors_cnt = 0;
        }


bool ConwayCell::mutate () {
          return false;     // Conway Cells never mutate
        }


ConwayCell* ConwayCell::clone () const {
            return new ConwayCell(*this);}
