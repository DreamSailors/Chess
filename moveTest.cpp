/***********************************************************************
* Program:
*    Project 3, Chess with Objects
*    Brother McCracken, CS165
* Author:
*    Jeffry Simpson, Sam Koontz 
* Summary: 
*    This fill will keep track of the move on the board
************************************************************************/

#include <iostream>
#include "move.h"
#include "board.h"
#include "piece.h"
#include "position.h"
using namespace std;

/*************************************
 * main
 **************************************/
int main()
{
   Move move1;
   string input;
   Move move2;
   Board board;
   Position source;
   //Piece sourcePiece;

   board.setup();   // Setup the new board
   board.display(); //display board

   
   for (;;)
   {
	   cout << "Enter a move: ";
	   cin >> input;
	   if (input == "e")
	   {
		   return 0;
	   }
	   try
	   {
		    
		   move1 = input;
		   cout << "    You entered: " << move1 << endl;
	   }
	   catch (string s)
	   {
		   cout << "Error reading first move: " << s << endl;
	   }

	   /*try
	   {
	   cout << "enter another move: ";
	   cin  >> move2;
	   cout << "you entered: " << move2 << endl;
	   }
	   catch (string s)
	   {
	   cout << "error reading second move: " << s << endl;
	   }

	   if (move1 == move2)
	   cout << "they are the same!\n";
	   else
	   cout << "they are different!\n";

	   move1 = move2;
	   cout << "after move1 = move2, then: " << move1 << " " << move2 << endl;
	   */

	   source = move1.getSrc();
	   cout << source;
	   //sourcePiece = board(source);

   }
   return 0;

}

