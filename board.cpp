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

/**************************************************************
 * Setup (Private)
 * Sets up the Board, called from the constructor
 *    INPUT: N/A
 *    OUTPUT N/A
 * 
 * Written by Jeffry Simpson
 *************************************************************/
void Board::setup()
{
   isAllocated = true; // setup board
   
   
    // the white army
   board[0][0] = new Rook  (true, 0,0 /*white*/);
   board[0][1] = new Knight(true, 0,1 /*white*/);
   board[0][2] = new Bishop(true, 0,2 /*white*/);
   board[0][3] = new Queen (true, 0,3 /*white*/);
   board[0][4] = new King  (true, 0,4 /*white*/);
   board[0][5] = new Bishop(true, 0,5 /*white*/);
   board[0][6] = new Knight(true, 0,6 /*white*/);
   board[0][7] = new Rook  (true, 0,7 /*white*/);

   // the pawns
   for (int col = 0; col < 8; col++)
   {
      board[1][col] = new Pawn  (true, 1, col  /*white*/);
      board[6][col] = new Pawn  (false, 6, col /*black*/);      
   }

   // the spaces
   for (int row = 2; row < 6; row++)
      for (int col = 0; col < 8; col++)
         board[row][col] = new Space(false,row,col);
   
   // the black army
   board[7][0] = new Rook  (false, 7,0 /*black*/);
   board[7][1] = new Knight(false, 7,1 /*black*/);
   board[7][2] = new Bishop(false, 7,2 /*black*/);
   board[7][3] = new Queen (false, 7,3 /*black*/);
   board[7][4] = new King  (false, 7,4 /*black*/);
   board[7][5] = new Bishop(false, 7,5 /*black*/);
   board[7][6] = new Knight(false, 7,6 /*black*/);
   board[7][7] = new Rook  (false, 7,7 /*black*/);

}

/**************************************************************
 * displayText (Private)
 * displays the text version of the board
 *    INPUT: N/A
 *    OUTPUT N/A
 * 
 * Written by Jeffry Simpson
 *************************************************************/
void Board::displayText() const
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

/**************************************************************
 * displayFancy (Private)
 * displays the more graphical version of the board
 *    INPUT: N/A
 *    OUTPUT N/A
 * 
 * Written by Jeffry Simpson
 *************************************************************/
void Board::displayFancy() const
{
   
   cout << "\E[H\E[2J";   //Clear the Terminal Screen
   
   cout << "    a  b  c  d  e  f  g  h \n";   //header
   // display the board
   for (int row = 7; row >= 0; row--)
   {
      cout << " " << row+1 << " ";
      for (int col = 0; col < 8; col++)
      {
         Piece * piece = board[row][col];   //get current piece

         char id = piece->getLetter();     //do letter manipulation
         if (id == 'P')                //change pawns to lowercase
            id = 'p';

         //CHange white pieces to uppercase except for pawns
         if(piece->getIsWhite() && (piece->getLetter() != 'p'))
            id = toupper(piece->getLetter());


         if(((row % 2 == 0) && (col%2 == 0)) || ((row % 2 == 1) && (col%2 == 1)))
            //redsquare
            if(board[row][col]->getIsWhite())  // White piece
               cout << BLACK_WHITE << id << NONE; 
            else
               cout << BLACK_BLACK  << id << NONE; 
         else
           //Whitesquare
            if(board[row][col]->getIsWhite())  // White piece
               cout << WHITE_WHITE << id << NONE;
            else
               cout <<  WHITE_BLACK  << id <<  NONE;

      }
      cout << " " << row+1 << endl;
   }
    cout << "    a  b  c  d  e  f  g  h \n";   // footer
   
}


void Board::makeMove(const Position & pos, Piece & piece)
{
	board[pos.getRow()][pos.getCol()] =  &piece;

}

/**************************************************************
 * Display (Private)
 * Determines which value to display based on isTest
 *    INPUT: N/A
 *    OUTPUT N/A
 * 
 * Written by Jeffry Simpson
 *************************************************************/
void Board::display() const
{

   if(isTest)
     displayText();
  else
      displayFancy();

      
}



/**************************************************************
 * Operator overload 
 *
 * Written by Jeffry Simpson
 *************************************************************/

 ostream & operator << (ostream & out, const Board & rhs)
 {
  
    rhs.display();

   return out;
 }

