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
    void setup();
    void display();
    
private:
    bool isTest;
    bool isAllocated;
    Piece * board[8][8];

};

#endif	/* BOARD_H */
