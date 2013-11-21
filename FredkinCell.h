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
        FredkinCell (char c) :   AbstractCell () {


            if ( c=='+') {
                 _isAlive = true;
                 age = 10;
            }
            else if (c >= '0' && c <= '9') {
                age = c - '0';
                _isAlive = true;
            }
        }
        
        void set_neighbors (int x) {
            neighbors_cnt = x;

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


        // ConwayCell* clone () const {
        //     return new ConwayCell(*this);}
};
#endif // FredkinCell_h
  