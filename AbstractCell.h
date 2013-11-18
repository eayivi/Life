// --------------------------
// projects/life/AbstractCell.h
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------

// --------
// includes
// --------

#include <iostream> // istream, ostream

class AbstractCell {

  private:
    bool state;
    int age;

  public:
    virtual bool turn() ;  // could check neighbors and follow rules   
};

    
