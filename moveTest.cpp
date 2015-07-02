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
using namespace std;

/*************************************
 * main
 **************************************/
int main()
{
   Move move1;
   Move move2;

   Board board;
   Space emptySpace(true,0,0);  //Create an empty Space piece to put in Dest

   try
   {
	   board.display(); //display board
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
            
           
            *****************************************
            * Your code here, I just changed the couts to be more clear to me 
             
           cout << move1.getSrc() << endl;
	   cout << "board[source]: " << board[move1.getSrc()] << endl;
	   cout << "source:" << endl
		   << "\t" << board[move1.getSrc()] << endl;
	   cout << "dest: " << endl
		   << "\t" << board[move1.getDes()] << endl;

	   board.makeMove(move1.getDes(), board[move1.getSrc()]);
	   board.makeMove(move1.getSrc(), board[move1.getDes()]);
	   */
  
           
           cout << "Execute Move \n";
	   cout << "Source Location: " << move1.getSrc() << endl;
	   cout << "Source Piece: " << board[move1.getSrc()] << endl;
           cout << "Destination Location: "  << move1.getDes() << endl;
           cout << "Destination Piece: "  << board[move1.getDes()]  << endl;
            
	   board.makeMove(move1.getDes(), board[move1.getSrc()]);  //put pieces from source into destination   
	   board.makeMove(move1.getSrc(),emptySpace); // put empty piece where the moving piece came
                                                      
   }
   
   return 0;
   

}

