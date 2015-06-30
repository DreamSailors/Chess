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


#ifndef CHESS_H
#define	CHESS_H

#include <iostream>
#include <cassert>
#include "move.h"
#include "position.h"

using namespace std;

#define WHITE_WHITE "\E[31;47m" // white square white piece
#define WHITE_BLACK "\E[30;47m" // white square black piece
#define BLACK_WHITE "\E[37;41m" // black square white piece
#define BLACK_BLACK "\E[30;41m" // black square black piece
#define RETURN      "\E[0m"     // setback to normal colors



/*****************************************
 * PIECE
 * The base piece class.  
 * 
 *****************************************/
class Piece 
{
public:
   Piece(bool isWhite, int row, int col) : isWhite(isWhite), position(row,col) {  }
   virtual ~Piece() { }
   bool getIsWhite() const                { return isWhite; }
   virtual char getLetter() const = 0;
   virtual int getScore() const = 0;
   friend ostream & operator << (ostream & out, const Piece & rhs);
   
protected:
    Position position;
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
   virtual int getScore() const    { return getIsWhite() ? 1000: -1000;}
   virtual char getLetter() const  { return getIsWhite() ? 'k' : 'K';}
    
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


#endif	/* CHESS_H */

