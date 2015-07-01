/* 
 * File:   board.h
 * Author: Jeffry Simpson
 *
 * Created on June 27, 2015, 7:46 PM
 */

#ifndef BOARD_H
#define	BOARD_H

#include "piece.h"

class Board {
public:
    Board();
    Board(const Board& orig);
    virtual ~Board();
  
    void setTest(bool test) {isTest = test;}
    bool getTest() const { return isTest; }
 
//    Piece & operator [] (const Position & pos)
//    {return *board[pos.getCol()][pos.getRow()];};
    
    friend ostream & operator << (ostream & out, const Board & rhs);
    
private:
    
    bool isTest;
    bool isAllocated;
    Piece * board[8][8];
    void setup();
    void display() const;
    void displayText() const;
    void displayFancy() const;
    

};

#endif	/* BOARD_H */

