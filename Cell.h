// --------
// Cell.h
// --------
#ifndef Cell_h
#define Cell_h

// --------
// includes
// --------
#include "Handle.h"
#include "AbstractCell.h"


class Cell : Handle<AbstractCell> {


	public:
	 	Cell(AbstractCell* p) : 
			Handle<AbstractCell> (p){};

};

 #endif // Cell_h 
