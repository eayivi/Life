// -----------
// AbstractCell.h
// -----------

#ifndef AbstractCell_h
#define AbstractCell_h

#include <iostream> // istream, ostream
#include <utility>  // !=
using namespace std;
class AbstractCell {

    private:
        
    protected:
        bool _isAlive;
        int neighbors_cnt;

    public:

        AbstractCell (bool alive, int neighbors_cnt = 0) :
                _isAlive(alive)
            {}

        bool get_liveness() {

            if (_isAlive == true) {
                return true;
            } else
                return false;
        }

        virtual void print_cell (ostream&) = 0;

        virtual void set_neighbors (int x) = 0;
/*
        AbstractCell (const AbstractCell& that) :
                _x (that._x),
                _y (that._y)
            {}
*/
        // virtual ~AbstractCell ()
        //     {}


       // virtual AbstractCell* clone () const = 0;
};

 #endif // AbstractCell_h
