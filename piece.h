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

using namespace std;

/*****************************************
 * PIECE
 * The base piece class.  
 * 
 *****************************************/
class Piece : Move
{
public:
   Piece(bool isWhite) : isWhite(isWhite) {                 }
   virtual ~Piece() { }
   bool getIsWhite() const                { return isWhite; }
   virtual char getLetter() const  = 0;
   virtual int getScore() const = 0;
   friend ostream & operator << (ostream & out, const Piece & rhs);
protected:
   bool isWhite;
};

class Space : public Piece
{
public:
   Space() : Piece(false)   {                    }
   virtual int getScore() const    { return 0;}
   virtual char getLetter() const  { return PIECE_EMPTY;}
   
};

class King : public Piece
{
public:
   King(const bool isWhite) : Piece(isWhite)    {                    }
   virtual int getScore() const    { return getIsWhite() ? 1000: -1000;}
   virtual char getLetter() const  { return getIsWhite() ? 'k' : 'K';}
   
};

class Queen : public Piece
{
   public:
      Queen(const bool isWhite) : Piece(isWhite)    {                    }
      virtual int getScore() const    { return getIsWhite() ? 9: -9;}
      virtual char getLetter() const  { return getIsWhite() ? 'q' : 'Q';}
   
};

class Pawn : public Piece
{
   public:
     Pawn(const bool isWhite) : Piece(isWhite)    {                    }
     virtual int getScore() const    { return getIsWhite() ? 1: -1;}
     virtual char getLetter() const  { return getIsWhite() ? 'p' : 'P';}
   
};

class Rook : public Piece
{
public:
      Rook(const bool isWhite) : Piece(isWhite)    {                    }
      virtual int getScore() const    { return getIsWhite() ? 5: -5;}
      virtual char getLetter() const  { return getIsWhite() ? 'r' : 'R';}
   
};

class Knight : public Piece
{
   public:
      Knight(const bool isWhite) : Piece(isWhite)    {                    }
      virtual int getScore() const    { return getIsWhite() ? 3: -3;}
      virtual char getLetter() const  { return getIsWhite() ? 'n' : 'N';}
   
};

class Bishop : public Piece
{
   public:
     Bishop(const bool isWhite) : Piece(isWhite)    {                    }
     virtual int getScore() const    { return getIsWhite() ? 3: -3;}
     virtual char getLetter() const  { return getIsWhite() ? 'b' : 'B';}
   
};


#endif	/* CHESS_H */

