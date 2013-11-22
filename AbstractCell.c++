//---------------
// AbstractCell.c++
// --------------
#include "AbstractCell.h"


AbstractCell::AbstractCell (bool alive, int neighbors) :
                _isAlive(alive), neighbors_cnt(neighbors)
            {}

bool AbstractCell::get_liveness() {

            if (_isAlive == true) {
                return true;
            } else
                return false;
        }


void AbstractCell::set_straight_neighbors (int x) {
            neighbors_cnt = x;      // not neighbors_cnt+=x, since it's a reset
        }


void AbstractCell::cometolife(){
                _isAlive = true;
        }
