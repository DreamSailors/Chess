/* 
 * File:   board.cpp
 * Author: Jeffry Simpson
 * 
 * Created on June 27, 2015, 7:46 PM
 */

#include "board.h"

Board::Board() :isTest(false), isAllocated(false) { setup();}   
Board::Board(const Board& orig) { }
Board::~Board() 
{ 
   // If board has been allocated then destroy everything
   if(isAllocated)
   {
      for (int row = 0; row < 8; row++)
         for (int col = 0; col < 8; col++)
            delete board[row][col];
   }

}

/*
 *   Use Setup so that we can use it when we open a file
 * 
 * 
 */

void Board::setup()
{
   isAllocated = true; // setup board
   
   
    // the white army
   board[0][0] = new Rook  (true, 7,0 /*white*/);
   board[0][1] = new Knight(true, 7,1 /*white*/);
   board[0][2] = new Bishop(true, 7,2 /*white*/);
   board[0][3] = new Queen (true, 7,3 /*white*/);
   board[0][4] = new King  (true, 7,4 /*white*/);
   board[0][5] = new Bishop(true, 7,5 /*white*/);
   board[0][6] = new Knight(true, 7,6 /*white*/);
   board[0][7] = new Rook  (true, 7,7 /*white*/);

   // the pawns
   for (int col = 0; col < 8; col++)
   {
      board[1][col] = new Pawn  (true, 6, col  /*white*/);
      board[6][col] = new Pawn  (false, 1, col /*black*/);      
   }

   // the spaces
   for (int row = 2; row < 6; row++)
      for (int col = 0; col < 8; col++)
         board[row][col] = new Space(false,row,col);
   
   // the black army
   board[7][0] = new Rook  (false, 0,0 /*black*/);
   board[7][1] = new Knight(false, 0,1 /*black*/);
   board[7][2] = new Bishop(false, 0,2 /*black*/);
   board[7][3] = new Queen (false, 0,3 /*black*/);
   board[7][4] = new King  (false, 0,4 /*black*/);
   board[7][5] = new Bishop(false, 0,5 /*black*/);
   board[7][6] = new Knight(false, 0,6 /*black*/);
   board[7][7] = new Rook  (false, 0,7 /*black*/);

}


void Board::display() const
{
   
   if(isTest)
   {
      cout << "   abcdefgh\n";
      // display the board
      for (int row = 7; row >= 0; row--)
      {
         cout << " " << row+1 << " ";
         for (int col = 0; col < 8; col++)
            cout << *board[row][col];
         cout << endl;
      }
   }
   else
   {
      cout << "   a  b  c  d  e  f  g  h \n";
      // display the board
      for (int row = 7; row >= 0; row--)
      {
         cout << " " << row+1 << " ";
         for (int col = 0; col < 8; col++)
            cout << *board[row][col];
         cout << endl;
      }
   }
}


void Board::makeMove(const Position & pos, Piece & piece)
{
	board[pos.getRow()][pos.getCol()] =  &piece;

}


 ostream & operator << (ostream & out, const Board & rhs)
 {
    
    rhs.display();
    
    return out;
 }

