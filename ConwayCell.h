// --------
// ConwayCell.h
// --------

// --------
// includes
// --------
#ifndef Cell_h
#define Cell_h

#include <iostream> // istream, ostream
#include <utility>  // !=
#include <iostream> // istream, ostream
#include "AbstractCell.h"

using namespace std;
class ConwayCell : public AbstractCell {

    private:
 

    protected:
        /*bool equals (const AbstractCell& that) const {
            if (const ConwayCell* const p = dynamic_cast<const ConwayCell*>(&that))
                return AbstractCell::equals(*p) && (_r == p->_r);
            return false;}*/

        /*std::istream& read (std::istream& in) {
            return AbstractCell::read(in) >> _r;}*/

        /*std::ostream& write (std::ostream& out) const {
            return AbstractCell::write(out) << " " << _r;}*/

    public:
        ConwayCell () :   AbstractCell () {
            _isAlive = true;
        }
        
        void set_neighbors (int x) {
            neighbors_cnt = x;

        }

        void print_cell (std::ostream& w)  {
            if (_isAlive)
                w << '*';
            else
                w << '.';
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

        // double area () const {
        //     return 3.14 * _r * _r;}

        // ConwayCell* clone () const {
        //     return new ConwayCell(*this);}

        // int radius () const {
        //     return _r;}
        };

 #endif // ConwayCell_h