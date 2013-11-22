// -----------
// AbstractCell.h
// -----------

#ifndef AbstractCell_h
#define AbstractCell_h

#include <iostream> 
#include <utility> 

using namespace std;


// ------
// AbstractCell
// ------

/**
 * AbstractCell is an interface for other cells
 * 
 */
class AbstractCell {

    protected:
        bool _isAlive;          /**< Status of the cell, alive or not*/
        int neighbors_cnt;      /**< Currren neighbor count */  

    public:
        /**AbstractCell Constructor to handle different types of the constructor invocator 
          */
        AbstractCell (bool alive =false, int neighbors = 0) ;

        // -----------
        // get_liveness
        // -----------
        
        /** 
          * Check status 
          */
        bool get_liveness() ;

        // -----------
        // print_cell
        // -----------
        
        /** 
          * Invoque the right method according to the object type
          */
        virtual void print_cell (ostream&) = 0;

        // -----------
        // set_straight_neighbors
        // -----------
        
        /** 
          * Update neighbor count
          */
        void set_straight_neighbors (int x) ;


        // -----------
        // cometolife
        // -----------
        
        /** 
          * Revive Cell
          */
        void cometolife();

        // -----------
        // set_diag_neighbors
        // -----------
        
        /** 
          *Invoque the right method according to the object type
          */
        virtual void set_diag_neighbors(int x) =0;

        // -----------
        // evolve
        // -----------
        
        /** 
          * Invoque the right method according to the object type
          */
        virtual void evolve() =0;
        
        // -----------
        // mutate
        // -----------
        
        /** 
          * Invoque the right method according to the object type
          */        
        virtual bool mutate() =0;

        // -----------
        // clone
        // -----------
        
        /** 
          * Invoque the right method according to the object type
          */
        virtual AbstractCell* clone () const = 0;};

 #endif // AbstractCell_h
