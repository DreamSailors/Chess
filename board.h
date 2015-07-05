/***********************************************************************
* Program:
*    Project 3, Chess            
*    Brother McCracken, CS165
* Author:
*    Jeffry Simpson, Samuel Koontz
* Summary: 
*    The driver program for the game of skeet
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/


#ifndef BOARD_H
#define	BOARD_H

#include "piece.h"

class Board {
public:
    Board();
    Board(const Board& orig);
    virtual ~Board();
    
    void makeMove(const Position & pos, Piece & piece);
    void setTest(bool test) {isTest = test;}
    bool getTest() const { return isTest; }
    Piece & operator [] (const Position & pos)
    {return *board[pos.getRow()][pos.getCol()];};
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

