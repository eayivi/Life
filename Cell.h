// --------
// Cell.h
// --------
#ifndef Cell_h
#define Cell_h

// --------
// includes
// --------
#include <iostream>
#include "Handle.h"
#include "AbstractCell.h"


class Cell : Handle<new FranklinCell> {


	// friend bool operator == (const Cell& lhs, const Cell& rhs) {
 //        return (lhs._x == rhs._x) && (lhs._y == rhs._y);}

 //    friend std::istream& operator >> (std::istream& lhs, Cell& rhs) {
 //        return lhs >> rhs._x >> rhs._y;}

 //    friend std::ostream& operator << (std::ostream& lhs, const Cell& rhs) {
 //        return lhs << rhs._x << " " << rhs._y;}

    private:     
		AbstractCell* abstractCell;

	public:
	 	Cell(AbstractCell* p) : 
			Handle<AbstractCell> (p){};

};



 #endif // Cell_h 
