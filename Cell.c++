#include <iostream>
#include "Cell.h"


class Cell {
    friend bool operator == (const Cell& lhs, const Cell& rhs) {
        return (lhs._x == rhs._x) && (lhs._y == rhs._y);}

    friend std::istream& operator >> (std::istream& lhs, Cell& rhs) {
        return lhs >> rhs._x >> rhs._y;}

    friend std::ostream& operator << (std::ostream& lhs, const Cell& rhs) {
        return lhs << rhs._x << " " << rhs._y;}

    private:
        int _x;
        int _y;

    public:
        Cell (int x, int y) :
                _x (x),
                _y (y)
            {}
/*
        Cell (const Cell& that) :
                _x (that._x),
                _y (that._y)
            {}

        ~Cell ()
            {}

        Cell& operator = (const Cell& that) {
            _x = that._x;
            _y = that._y;
            return *this;}
*/
        double area () const {
            return 0;}

        void move (int x, int y) {
            _x = x;
            _y = y;}};
