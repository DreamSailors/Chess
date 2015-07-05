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
#include <sstream>
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
   char boardLetters[8][8];
   void setBoardLetters(int i, int j, char letter)
   {
	   boardLetters[i][j] = letter;
   }
   friend ostream & operator << (ostream & out, const Piece & rhs);
   Position getPos()         { return this->position; }
   virtual void setValidMoveList() { /*validMoveList = '\0';*/ };
   virtual void setPos(Position pos) { this->position = pos; };
   string legalMoves;
   void setMove(bool moved) {this->moved = moved;};

protected:
    Position position;
    bool moved;
    bool isWhite;
    



	
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
	Position possibleMoveArray[8][1];
	virtual int getScore() const    { return getIsWhite() ? 1000 : -1000; }
	virtual char getLetter() const  { return getIsWhite() ? 'k' : 'K'; }
	void setValidMoveList()
	{
		bool stop;
		int moveDirection[8][2] =
		{
			{ 0, 1 }, //right
			{ 1, 0 },//up
			{ 1, 1 },//up-right
			{ 1, -1 },//up-left
			{ 0, -1 }, //left
			{ -1, -1 }, //down-left
			{ -1, 0 }, //down
			{ -1, 1 }, //down-right

		};
		int pieceRow = this->position.getRow();
		int pieceCol = this->position.getCol();
		Position posTemp;
		int f = 0;
		for (int inc = 0; inc < 8; inc++)
		{
			stop = false;
			int i = pieceRow;
			int j = pieceCol;

			i += moveDirection[inc][0];
			j += moveDirection[inc][1];
			posTemp.setRow(i);
			posTemp.setCol(j);
			if (posTemp.isValid())
			{
				if (boardLetters[i][j] != ' ')
				{
					if (!(!isupper(boardLetters[i][j]) && this->getIsWhite() ||
						isupper(boardLetters[i][j]) && !this->getIsWhite()))
					{
						legalMoves += this->position.getPosString();
						legalMoves += posTemp.getPosString();
						legalMoves += tolower(boardLetters[i][j]);
						legalMoves += '\n';
					}
				}
				else
				{
					legalMoves += this->position.getPosString();
					legalMoves += posTemp.getPosString();
					legalMoves += '\n';
				}
			}
		}
	}
};

class Queen : public Piece
{
   public:
      Queen(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
      { };

	  Position possibleMoveArray[7][7];
      virtual int getScore() const    { return getIsWhite() ? 9: -9;}
      virtual char getLetter() const  { return getIsWhite() ? 'q' : 'Q';}
	  void setValidMoveList()
	  {
		  bool stop;
		  int moveDirection[8][2] =
		  {
			  { 0, 1 },   //right
			  { 1, 0 },   //up
			  { 1, 1 },   //up-right
			  { 1, -1 },  //up-left
			  { 0, -1 },  //left
			  { -1, -1 }, //down-left
			  { -1, 0 },  //down
			  { -1, 1 }, //down-right
			  
		  };


		  int pieceRow = this->position.getRow();
		  int pieceCol = this->position.getCol();
		  Position posTemp;
		  int f = 0;
		  for (int inc = 0; inc < 8; inc++)
		  {
			 stop = false;
			int i = pieceRow;
			int j = pieceCol;
			 
			 while (!stop)
			  {
				  i += moveDirection[inc][0];
				  j += moveDirection[inc][1];
				  posTemp.setRow(i);
				  posTemp.setCol(j);
				  if (posTemp.isInvalid())
				  {
					  stop = true;
					  posTemp.setValid();
					  break;
				  }
				  if (boardLetters[i][j] != ' ')
				  {
					  stop = true;
					  if (!isupper(boardLetters[i][j]) && this->getIsWhite() ||
						  isupper(boardLetters[i][j]) && !this->getIsWhite())
						  break;
				  }
				  legalMoves += this->position.getPosString();
				  legalMoves += posTemp.getPosString();
				  if (stop)
					  legalMoves += tolower(boardLetters[i][j]);
				  legalMoves += '\n';
			  }
		  }
	}
};

class Pawn : public Piece
{
   public:
     Pawn(const bool isWhite, int row, int col) : Piece(isWhite,row,col)
      { };
     virtual int getScore() const    { return getIsWhite() ? 1: -1;}
     virtual char getLetter() const  { return getIsWhite() ? 'p' : 'P';}
	 void setValidMoveList()
	 {
		 int moveD;
		 if (this->getIsWhite())
			 moveD = 1;
		 else
			 moveD = -1;
		 int moveDirection[3][2] =
		 {
			 { 1, 1 },  //right
			 { 1, 0 },  //straight
			 { 1, -1 }, //left
		 };
		 int pieceRow = this->position.getRow();
		 int pieceCol = this->position.getCol();
		 Position posTemp;
		 for (int inc = 0; inc < 3; inc++) //check for normal movement
		 {
			 int i = pieceRow;
			 int j = pieceCol;
			 i += (moveDirection[inc][0]) * moveD; //reverses direction for black pawns
			 j += moveDirection[inc][1];
			 posTemp.setRow(i);
			 posTemp.setCol(j);
			 if (posTemp.isValid())
			 {
				 if (moveDirection[inc][1] == 0 && boardLetters[i][j] == ' ')
				 {
					 legalMoves += this->position.getPosString();
					 legalMoves += posTemp.getPosString();
					 legalMoves += '\n';
				 }
				 if (moveDirection[inc][1] != 0 && boardLetters[i][j] != ' ') 
				 {
					if(!(!isupper(boardLetters[i][j]) && this->getIsWhite() ||
					   isupper(boardLetters[i][j]) && !this->getIsWhite()))
					 {
						 legalMoves += this->position.getPosString();
						 legalMoves += posTemp.getPosString();
						 legalMoves += tolower(boardLetters[i][j]);
						 legalMoves += '\n';
					 }
				 }
			 }
			 posTemp.setValid();
		 }
		 if (!this->moved)
		 {
			 if (boardLetters[pieceRow + moveD][pieceCol] == ' ' && boardLetters[pieceRow + 2 * moveD][pieceCol] == ' ');
			 {
				 posTemp.setRow(pieceRow + 2 * moveD);
				 posTemp.setCol(pieceCol);
				 legalMoves += this->position.getPosString();
				 legalMoves += posTemp.getPosString();
				 legalMoves += '\n';
			 }
		 }
	}
};

class Rook : public Piece
{
public:
      Rook(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
      { };
	  Position possibleMoveArray[3][7];
      virtual int getScore() const    { return getIsWhite() ? 5: -5;}
      virtual char getLetter() const  { return getIsWhite() ? 'r' : 'R';}
	  void setValidMoveList()
	  {
			  bool stop;
			  int moveDirection[4][2] =
			  {
				  { 0, 1 },  //right
				  { 1, 0 },  //up
				  { 0, -1 }, //left
				  { -1, 0 }, //down
			  };
			  int pieceRow = this->position.getRow();
			  int pieceCol = this->position.getCol();
			  Position posTemp;
			  for (int inc = 0; inc < 4; inc++)
			  {
				  stop = false;
				  int i = pieceRow;
				  int j = pieceCol;
				  while (!stop)
				  {
					
					  i += moveDirection[inc][0];
					  j += moveDirection[inc][1];
					  posTemp.setRow(i);
					  posTemp.setCol(j);
					  if (posTemp.isInvalid())
					  {
						  stop = true;
						  posTemp.setValid();
						  break;
					  }
					  if (boardLetters[i][j] != ' ')
					  {
						  stop = true;
						  if (!isupper(boardLetters[i][j]) && this->getIsWhite() ||
							  isupper(boardLetters[i][j]) && !this->getIsWhite())
							  break;
					  }
					  legalMoves += this->position.getPosString();
					  legalMoves += posTemp.getPosString();
					  if (stop)
						  legalMoves += tolower(boardLetters[i][j]);
					  legalMoves += '\n';
				  }
			  }
	  }
};

class Knight : public Piece
{
public:
	Knight(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
	{ };
	Position possibleMoveArray[8][1];
	virtual int getScore() const    { return getIsWhite() ? 3 : -3; }
	virtual char getLetter() const  { return getIsWhite() ? 'n' : 'N'; }
	void setValidMoveList()
	{
		bool stop;
		int moveDirection[8][2] =
		{
			{ 1,2 },    //up 1 right 2
			{ 2,1 },    //up 2 right 1
			{ 1,-2 },   //up 1 left 2
			{ 2,-1 },   //up 2 left 1
			{ -1, 2 },  //down 1 right 2
			{ -2, 1 },  //down 2 right 1
			{ -1, -2},  //down 1 left 2
			{ -2, -1 }, //down 2 left 1
		};
		int pieceRow = this->position.getRow();
		int pieceCol = this->position.getCol();
		Position posTemp;
		for (int inc = 0; inc < 8; inc++)
		{
			stop = false;
			int i = pieceRow;
			int j = pieceCol;
			i += moveDirection[inc][0];
			j += moveDirection[inc][1];
			posTemp.setRow(i);
			posTemp.setCol(j);
			if (posTemp.isValid())
			{
				if (boardLetters[i][j] != ' ')
				{
					if (!(!isupper(boardLetters[i][j]) && this->getIsWhite() ||
						isupper(boardLetters[i][j]) && !this->getIsWhite()))
					{
						legalMoves += this->position.getPosString();
						legalMoves += posTemp.getPosString();
						legalMoves += tolower(boardLetters[i][j]);
						legalMoves += '\n';
					}
				}
				else
				{
					legalMoves += this->position.getPosString();
					legalMoves += posTemp.getPosString();
					legalMoves += '\n';
				}
			}
			posTemp.setValid();
		}
	}
};

class Bishop : public Piece
{
   public:
     Bishop(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
      { };
	 Position possibleMoveArray[3][7];
     virtual int getScore() const    { return getIsWhite() ? 3: -3;}
     virtual char getLetter() const  { return getIsWhite() ? 'b' : 'B';}
	 void setValidMoveList()
	 {
		 bool stop;
		 int moveDirection[4][2] =
		 {
			 { 1, 1 },   //up-right
			 { 1, -1 },  //up-left
			 { -1, -1 }, //down-left
			 { -1, 1 },  //down-right
		 };
		 int pieceRow = this->position.getRow();
		 int pieceCol = this->position.getCol();
		 Position posTemp;
		 for (int inc = 0; inc < 4; inc++)
		 {
			 stop = false;
			 int i = pieceRow;
			 int j = pieceCol;
			 while (!stop)
			 {
				 i += moveDirection[inc][0];
				 j += moveDirection[inc][1];
				 posTemp.setRow(i);
				 posTemp.setCol(j);
				 if (posTemp.isInvalid())
				 {
					 stop = true;
					 posTemp.setValid();
					 break;
				 }
				 if (boardLetters[i][j] != ' ')
				 {
					 stop = true;
					 if (!isupper(boardLetters[i][j]) && this->getIsWhite() ||
						 isupper(boardLetters[i][j]) && !this->getIsWhite())
						 break;
				 }
				 legalMoves += this->position.getPosString();
				 legalMoves += posTemp.getPosString();
				 if (stop)
					 legalMoves += tolower(boardLetters[i][j]);
				 legalMoves += '\n';
			 }
		 }
	 }
};


#endif	/* PIECE.H */

