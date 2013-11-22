// --------------
// TestLife.c++
// --------------

#define private public
#define protected public

// includes
#include <iostream>
#include <sstream>
#include <string>
#include "gtest/gtest.h"

#include "Life.h"


using namespace std;

TEST(ConwayCell, Constructor_default ) {
   ConwayCell c;
   ASSERT_TRUE(!c._isAlive);

} 

TEST(ConwayCell, Constructor_alive) {
   ConwayCell c (true);
    ASSERT_TRUE(c._isAlive);
} 

TEST(ConwayCell, Constructor_set_alive) {
    ConwayCell c;
    c._isAlive = true;
    ASSERT_TRUE(c._isAlive);
} 



TEST(ConwayCell, print_live) {
        std::ostringstream w;
        ConwayCell X(true);
        X.print_cell(w);
    ASSERT_TRUE(w.str() == "*");
}

TEST(ConwayCell, print_dead) {
        std::ostringstream w;
        ConwayCell X(false);
        X.print_cell(w);
    ASSERT_TRUE(w.str() == ".");
}


TEST(ConwayCell, Set_neighbors) {
   assert(true);
} 

TEST(ConwayCell, Set_diag_neighbors) {
    ASSERT_TRUE(true);
} 


TEST(ConwayCell, Evolve ) {
   assert(true);
} 

TEST(ConwayCell, Mutate) {
   assert(true);
} 


TEST(FredkinCell, Constructor_default ) {
   FredkinCell c;
   ASSERT_TRUE(!c._isAlive);

} 

TEST(FredkinCell, Constructor_set_alive) {
    FredkinCell c;
    c._isAlive = true;
    ASSERT_TRUE(c._isAlive);
} 


TEST(Life, method1 ) {
   assert(true);
} 

TEST(Life, method2) {
   assert(true);
} 

TEST(Life, method3) {
   assert(true);
} 

TEST(Life, method4) {
   assert(true);
} 


TEST(Cell, method1 ) {
   assert(true);
} 

TEST(Cell, method2) {
   assert(true);
} 

TEST(Cell, method3) {
   assert(true);
} 

TEST(Cell, method4) {
   assert(true);
} 
