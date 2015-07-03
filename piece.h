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


#ifndef PIECE_H
#define	PIECE_H

#include <iostream>
#include <cassert>
#include "move.h"
#include "position.h"


using namespace std;

#define WHITE_WHITE "\E[31;47m " // white square white piece
#define WHITE_BLACK "\E[30;47m " // white square black piece
#define BLACK_WHITE "\E[37;41m " // black square white piece
#define BLACK_BLACK "\E[30;41m " // black square black piece
#define NONE        " \E[0m"     // setback to normal colors



/*****************************************
 * PIECE
 * The base piece class.  
 * 
 *****************************************/
class Piece 
{
public:
	
   Piece(bool isWhite, int row, int col) : isWhite(isWhite), position(row, col), moved(false) { setValidMoveList(); }
   virtual ~Piece() { }
   bool getIsWhite() const          { return isWhite; }
   bool hasMoved()   const          {return moved; }
   virtual char getLetter() const  = 0;
   virtual int getScore() const = 0;
   
   //string getValidMoveList() { return validMoveList; }
   friend ostream & operator << (ostream & out, const Piece & rhs);
   Position getPos()         { return this->position; }
   virtual void setValidMoveList() { /*validMoveList = '\0';*/ };
   virtual void setPos(Position pos) { this->position = pos; };
   
protected:
    Position position;
    bool moved;
    bool isWhite;
    void setMove(bool moved) {this->moved = moved;};


	
};

class Space : public Piece
{
public:
   Space(bool isWhite, int row, int col) : Piece(isWhite, row , col)   
   { };
   virtual int getScore() const    { return 0;}
   virtual char getLetter() const  { return PIECE_EMPTY;}
   
};

class King : public Piece
{
public:
	King(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
	{ };
	virtual int getScore() const    { return getIsWhite() ? 1000 : -1000; }
	virtual char getLetter() const  { return getIsWhite() ? 'k' : 'K'; }
	void setValidMoveList()
	{
		Position possibleMoveArray[8][1];
		possibleMoveArray[0][0] = this->getPos() += RIGHT;
		possibleMoveArray[1][0] = this->getPos() += UP_RIGHT;
		possibleMoveArray[2][0] = this->getPos() += UP;
		possibleMoveArray[3][0] = this->getPos() += UP_LEFT;
		possibleMoveArray[4][0] = this->getPos() += LEFT;
		possibleMoveArray[5][0] = this->getPos() += DOWN_LEFT;
		possibleMoveArray[6][0] = this->getPos() += DOWN;
		possibleMoveArray[7][0] = this->getPos() += DOWN_RIGHT;

		cout << this->getPos();
		for (int i = 0; i < 8; i++)
		{
			cout << possibleMoveArray[i][0] << " isValid: " << possibleMoveArray[i][0].isValid() << endl;
		}
	}
};

class Queen : public Piece
{
   public:
      Queen(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
      { };
      virtual int getScore() const    { return getIsWhite() ? 9: -9;}
      virtual char getLetter() const  { return getIsWhite() ? 'q' : 'Q';}
   
};

class Pawn : public Piece
{
   public:
     Pawn(const bool isWhite, int row, int col) : Piece(isWhite,row,col)
      { };
     virtual int getScore() const    { return getIsWhite() ? 1: -1;}
     virtual char getLetter() const  { return getIsWhite() ? 'p' : 'P';}
   
};

class Rook : public Piece
{
public:
      Rook(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
      { };
      virtual int getScore() const    { return getIsWhite() ? 5: -5;}
      virtual char getLetter() const  { return getIsWhite() ? 'r' : 'R';}
	  void setValidMoveList()
	  {
		  Position possibleMoveArray[8][8];
		  for (int i = 0; i < 8; i++)
			  possibleMoveArray[0][i] = this->getPos() += RIGHT;
		  for (int i = 0; i < 8; i++)
			  possibleMoveArray[1][i] = this->getPos() += UP_RIGHT;
		  for (int i = 0; i < 8; i++)
			  possibleMoveArray[2][i] = this->getPos() += UP;
		  for (int i = 0; i < 8; i++)
			  possibleMoveArray[3][i] = this->getPos() += UP_LEFT;
		  for (int i = 0; i < 8; i++)
			  possibleMoveArray[4][i] = this->getPos() += LEFT;
		  for (int i = 0; i < 8; i++)
			  possibleMoveArray[5][i] = this->getPos() += DOWN_LEFT;
		  for (int i = 0; i < 8; i++)
			  possibleMoveArray[6][i] = this->getPos() += DOWN;
		  for (int i = 0; i < 8; i++)
			  possibleMoveArray[7][i] = this->getPos() += DOWN_RIGHT;

		  cout << this->getPos();
		  for (int i = 0; i < 8; i++)
		  {
			  for (int j = 0; j < 8; j ++)
			  cout << possibleMoveArray[i][j] << " isValid: " << possibleMoveArray[i][0].isValid() << endl;
		  }
	  }
};

class Knight : public Piece
{
   public:
      Knight(const bool isWhite, int row, int col) : Piece(isWhite, row,col)
      { };
      virtual int getScore() const    { return getIsWhite() ? 3: -3;}
      virtual char getLetter() const  { return getIsWhite() ? 'n' : 'N';}
   
};

class Bishop : public Piece
{
   public:
     Bishop(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
      { };
     virtual int getScore() const    { return getIsWhite() ? 3: -3;}
     virtual char getLetter() const  { return getIsWhite() ? 'b' : 'B';}
   
};


#endif	/* PIECE.H */

