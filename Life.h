#ifndef Life_h
#define Life_h

// --------
// includes
// --------

#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class Life{

    private:
      int row_size; 
      int col_size;  
     
     public:    
      vector< vector<void*> > board; 

    public: 
         Life(int, int){};
 };



 #endif // Life_h