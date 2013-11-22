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

        AbstractCell (bool alive =false, int neighbors = 0) ;

        bool get_liveness() ;

        virtual void print_cell (ostream&) = 0;

        void set_straight_neighbors (int x) ;

        void flipLiveStatus() ;

        void cometolife();

        virtual void set_diag_neighbors(int x) =0;

        virtual void evolve() =0;

        virtual bool mutate() =0;

        virtual AbstractCell* clone () const = 0;

};

 #endif // AbstractCell_h
