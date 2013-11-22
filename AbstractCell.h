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

        AbstractCell (bool alive =false, int neighbors = 0) :
                _isAlive(alive), neighbors_cnt(neighbors)
            {}

        bool get_liveness() {

            if (_isAlive == true) {
                return true;
            } else
                return false;
        }

        virtual void print_cell (ostream&) = 0;

        void set_straight_neighbors (int x) {
            neighbors_cnt = x;      // not neighbors_cnt+=x, since it's a reset
        };

        void flipLiveStatus(){
            if(_isAlive){
                _isAlive = false;
            }else{
                _isAlive = true;
            }
        }

        void cometolife(){
                _isAlive = true;
        }

        virtual void set_diag_neighbors(int x) =0;

        virtual void evolve() =0;

        virtual bool mutate() =0;

        virtual AbstractCell* clone () const = 0;


/*
        AbstractCell (const AbstractCell& that) :
                _x (that._x),
                _y (that._y)
            {}

        // virtual ~AbstractCell ()
             {}

*/
             
};

 #endif // AbstractCell_h
