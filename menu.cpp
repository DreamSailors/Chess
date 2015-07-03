/* 
 * File:   menu.cpp
 * Author: Jeffry Simpson
 * 
 * Created on July 1, 2015, 7:55 AM
 */

#include "menu.h"
#include "move.h"
//text

Menu::Menu() : playerPrompt(WHITEPLAYER) { setQuitGame(false); }
Menu::Menu(const Menu& orig) { }
Menu::~Menu() { }
Board board;
Move move1;
Space emptySpace(true, 0, 0);  //Create an empty Space piece to put in Dest

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
   else if (x == "test" || x == "Test" || x == "TEST")
	   menuOption = TEST;
   else if (x == "rank" || x == "Rank" || x == "RANK")
	   menuOption = RANK;
   else
   {
	   menuOption = MOVE;
   }
}


void Menu::processInput() 
{
   switch(menuOption)
   {
      case QUIT:
		  this->leaveGame();
		  break;
      case QUESTION:
         this->displayMenu();
         break;
      case TEST:
		 this->boardFlip();
         break;  
	  case READ:
		  break;
	  case HELP:
		  this->displayHelp();
		  break;
	  case MOVE:
		  this->makeMove();
      //default:
         //cout << "invalid entry, please try again\n";
   }
}

void Menu::leaveGame()
{
	cout << "save?"; //save file stuff goes here
	setQuitGame(true);
}


void Menu::displayMenu()
{

   cout << "Options:\n";
   cout << "?      Display these options\n";
   cout << "b2b4   Specify a move using the Smith Notation\n";
   cout << "read   Read a saved game from a file\n";
   cout << "help   Display all possible moves for a given piece\n";
   cout << "test   Simple display for test purposes\n";
   cout << "rank   Who is winning?  What is the rank\n";
   cout << "quit   Leave the game. You will be prompted to save\n";
}
void Menu::boardFlip() //changes board to and from test mode
{
	board.setTest(!board.getTest());
	cout << board;
}

void Menu::readGame()
{
	;
}
void Menu::displayHelp()
{
   cout << "Which piece would you like to find the moves for?";
   
}

void Menu::makeMove()
{
	move1 = userInput;
	this->checkSameColor(); //check that the move piece matches the turn
	if (getIsSameColor())
	{
		board.makeMove(move1.getDes(), board[move1.getSrc()]);  //put pieces from source into destination   
		board.makeMove(move1.getSrc(), emptySpace); // put empty piece where the moving piece came
		this->setPrompt();
		cout << board;
	}
	else
		cout << "Wait your turn!\n";
}

void Menu::checkSameColor()
{
	if ((playerPrompt == WHITEPLAYER && board[move1.getSrc()].getIsWhite() == true) ||
		(playerPrompt == BLACKPLAYER && board[move1.getSrc()].getIsWhite() == false))
		setIsSameColor(true);
	else
		setIsSameColor(false);
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