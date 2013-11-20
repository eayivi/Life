// -----------
// AbstractCell.h
// -----------

#ifndef AbstractCell_h
#define AbstractCell_h

#include <iostream> // istream, ostream
#include <utility>  // !=

class AbstractCell {
    // friend bool operator == (const AbstractCell& lhs, const AbstractCell& rhs) {
    //     return lhs.equals(rhs);}

    // friend std::istream& operator >> (std::istream& lhs, AbstractCell& rhs) {
    //     return rhs.read(lhs);}

    // friend std::ostream& operator << (std::ostream& lhs, const AbstractCell& rhs) {
    //     return rhs.write(lhs);}

    private:
        bool _isAlive;
        int _x;
        int _y;


    protected:
        AbstractCell& operator = (const AbstractCell& that) {
            _x = that._x;
            _y = that._y;
            return *this;}

        // virtual bool equals (const AbstractCell& that) const = 0;

        // virtual std::istream& read (std::istream& in) = 0;

        // virtual std::ostream& write (std::ostream& out) const = 0;

    public:
        AbstractCell (bool alive, int x, int y) :
                _isAlive(alive),
                _x (x),
                _y (y)
            {}

/*
        AbstractCell (const AbstractCell& that) :
                _x (that._x),
                _y (that._y)
            {}
*/
        virtual ~AbstractCell ()
            {}

        virtual double area () const = 0;

        virtual AbstractCell* clone () const = 0;

        void move (int x, int y) {
            _x = x;
            _y = y;}};

 #endif // AbstractCell_h
