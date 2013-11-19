// --------------------------
// projects/life/ConwayCell.h
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------

// --------
// includes
// --------

#include <iostream> // istream, ostream

class ConwayCell : public AbstractCell {
    private:
        int _r;

    protected:
        virtual bool equals (const AbstractCell& that) const {
            if (const ConwayCell* const p = dynamic_cast<const ConwayCell*>(&that))
                return AbstractCell::equals(*p) && (_r == p->_r);
            return false;}

        virtual std::istream& read (std::istream& in) {
            return AbstractCell::read(in) >> _r;}

        virtual std::ostream& write (std::ostream& out) const {
            return AbstractCell::write(out) << " " << _r;}

    public:
        Circle (int x, int y, int r) :
                AbstractCell (x, y),
                _r            (r)
            {}
/*
        Circle (const Circle& that) :
                AbstractCell (that),
                _r            (that._r)
            {}

        virtual ~Circle ()
            {}

        Circle& operator = (const Circle& that) {
            AbstractCell::operator=(that);
            _r = that._r;
            return *this;}
*/

        virtual double area () const {
            return 3.14 * _r * _r;}

        virtual ConwayCell* clone () const {
            return new Circle(*this);}

        int radius () const {
            return _r;}};
 
