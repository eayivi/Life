 // --------
// FredkinCell.c++
// --------
#include <iostream> 
#include <utility>  
#include <iostream> 

// class FredkinCell : public AbstractCell {
//     private:
//         int _r;

//     protected:
//         virtual bool equals (const AbstractCell& that) const {
//             if (const FredkinCell* const p = dynamic_cast<const FredkinCell*>(&that))
//                 return AbstractCell::equals(*p) && (_r == p->_r);
//             return false;}

//         virtual std::istream& read (std::istream& in) {
//             return AbstractCell::read(in) >> _r;}

//         virtual std::ostream& write (std::ostream& out) const {
//             return AbstractCell::write(out) << " " << _r;}

//     public:
//         FredkinCell (int x, int y, int r) :
//                 AbstractCell (x, y),
//                 _r            (r)
//             {}
// /*
//         FredkinCell (const ConwayCell& that) :
//                 AbstractCell (that),
//                 _r            (that._r)
//             {}

//         virtual ~FredkinCell ()
//             {}

//         FredkinCell& operator = (const FredkinCell& that) {
//             AbstractCell::operator=(that);
//             _r = that._r;
//             return *this;}
// */

//         virtual double area () const {
//             return 3.14 * _r * _r;}

//         virtual FredkinCell* clone () const {
//             return new ConwayCell(*this);}

//         int radius () const {
//             return _r;}};
 

