/* 
 * File:   board.cpp
 * Author: Jeffry Simpson
 * 
 * Created on June 27, 2015, 7:46 PM
 */

#include "board.h"

Board::Board() :isTest(false), isAllocated(false) { }

Board::Board(const Board& orig) { }

Board::~Board() 
{ 
   // destroy everything
   if(isAllocated)
   {
      for (int row = 0; row < 8; row++)
         for (int col = 0; col < 8; col++)
            delete board[row][col];
   }

}

void Board::setup()
{
   isAllocated = true; // setup board
   
   
    // the white army
   board[0][0] = new Rook  (true /*white*/);
   board[0][1] = new Knight(true /*white*/);
   board[0][2] = new Bishop(true /*white*/);
   board[0][3] = new Queen (true /*white*/);
   board[0][4] = new King  (true /*white*/);
   board[0][5] = new Bishop(true /*white*/);
   board[0][6] = new Knight(true /*white*/);
   board[0][7] = new Rook  (true /*white*/);

   // the pawns
   for (int col = 0; col < 8; col++)
   {
      board[1][col] = new Pawn  (true  /*white*/);
      board[6][col] = new Pawn  (false /*black*/);      
   }

   // the spaces
   for (int row = 2; row < 6; row++)
      for (int col = 0; col < 8; col++)
         board[row][col] = new Space();
   
   // the black army
   board[7][0] = new Rook  (false /*black*/);
   board[7][1] = new Knight(false /*black*/);
   board[7][2] = new Bishop(false /*black*/);
   board[7][3] = new Queen (false /*black*/);
   board[7][4] = new King  (false /*black*/);
   board[7][5] = new Bishop(false /*black*/);
   board[7][6] = new Knight(false /*black*/);
   board[7][7] = new Rook  (false /*black*/);

}

void Board::display()
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
      cout << "Fancy stuff output here";
   }
}

