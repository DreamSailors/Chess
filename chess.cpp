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

#include <cstdlib>
#include <iostream>    // for CIN and COUT
#include "piece.h"
#include "board.h"
#include "menu.h"

using namespace std;

/**********************************************************************
 * MAIN: This is a driver program for our various piece classes.
 *       You are not allowed to change MAIN in any way
 ***********************************************************************/
int main()
{
   Board board;
   Menu menu;

   cout << board;
   while (!menu.getQuitGame())
   {
	   
	   cout << menu;
   }
//   menu.getUserInput();
//   menu.displayMenu();
   
   

   

   
  // board.setTest(true);   //temp test setup
  // board.display();  //display the content
  
   


   return 0;
}


