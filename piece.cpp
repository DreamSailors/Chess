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

#include "piece.h"
#include "board.h"


//Board board;
/*********************************************
 * OUT << PIECE
 * Insertion operator for the piece
 ********************************************/
ostream & operator << (ostream & out, const Piece & rhs)
{
   out << rhs.getLetter();
   return out;
}

string King::setValidKing(const Position & pos)
{
	//cout << board[pos];
	Position possibleMoveArray[8][1];
	possibleMoveArray[0][0] = this->getPos() += RIGHT;
	possibleMoveArray[1][0] = this->getPos() += UP_RIGHT;
	possibleMoveArray[2][0] = this->getPos() += UP;

	
	cout << this->getPos();
	cout << possibleMoveArray[0][0];
	cout << possibleMoveArray[1][0];


	return "test";
}
