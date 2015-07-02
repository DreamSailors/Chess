/* 
 * File:   menu.cpp
 * Author: Jeffry Simpson
 * 
 * Created on July 1, 2015, 7:55 AM
 */

#include "menu.h"

Menu::Menu() : playerPrompt(WHITEPLAYER) { }
Menu::Menu(const Menu& orig) { }
Menu::~Menu() { }


void Menu::getUserInput()
{

   cout << getPrompt() << " ";
   cin >> userInput;
  
}

void Menu::pickMenuOption()
{
   string x = userInput;
   
   if ( x == "quit" || x == "Quit" || x == "QUIT")
      menuOption = QUIT;
   else if ( x == "read" || x == "Read" || x == "READ")
      menuOption = READ;
   else if ( x == "?" )
      menuOption = QUESTION;
   else if ( x == "Help"  || x == "help" || x == "HELP")
      menuOption = HELP;
   else if (x == "test" || x == "Test"  || x == "TEST")
      menuOption =  TEST;
   else
      menuOption = MOVE;
}


void Menu::processInput() 
{
   Board board;
   
   switch(menuOption)
   {
      case QUESTION:
         cout << " question";
         this->displayMenu();
         break;
      case TEST:
         cout << "test";
         board.setTest(!board.getTest());
         cout << board;
         break;
         
      default:
         cout << "invalid entry, please try again\n";
   }
}

void Menu::displayMenu()
{

   cout << "Options:\n";
   cout << "?      Display these options\n";
   cout << "b2b4   Specify a move using the Smith Notation\n";
   cout << "read   Read a saved game from a file\n";
   cout << "help   Display all possible moves for a given piece";
   cout << "test   Simple display for test purposes\n";
   cout << "rank   Who is winning?  What is the rank\n";
   cout << "quit   Leave the game. You will be prompted to save\n";
}

void Menu::displayHelp()
{
   cout << "Which piece would you like to find the moves for?";
   
}

void Menu::setPrompt() 
{
        
   if(playerPrompt == WHITEPLAYER)
      playerPrompt = BLACKPLAYER;
   else
      playerPrompt = WHITEPLAYER;
   
 
}

ostream & operator << (ostream & out,  Menu & rhs) 
{
   rhs.getUserInput();
   rhs.pickMenuOption();
   rhs.processInput();
   //rhs.displayMenu();
   
   return out;
}