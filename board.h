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
	void makeMove(const Position & pos, Piece & piece);
    void setTest(bool test) {isTest = test;}
    bool getTest() const { return isTest; }
    void setup();
    void display() const;
    
    Piece & operator [] (const Position & pos)
    {return *board[pos.getRow()][pos.getCol()];};


    friend ostream & operator << (ostream & out, const Board & rhs);
    
private:
    bool isTest;
    bool isAllocated;
    Piece * board[8][8];

};

#endif	/* BOARD_H */

