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


#include "chess.h"

using namespace std;

Chess::Chess() : playerPrompt(WHITEPLAYER) { setQuitGame(false); }
Chess::Chess(const Chess& orig) { }
Chess::~Chess() { }

Board board;
Move move1;
Space emptyPiece(true, 0, 0);  //Create an empty Space piece to put in Dest

void Chess::getUserInput()
{

   cout << getPrompt() << " ";
   cin >> userInput;
  
}

void Chess::pickMenuOption()
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


void Chess::processInput() 
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

void Chess::leaveGame()
{
	cout << "save?"; //save file stuff goes here
	setQuitGame(true);
}


void Chess::displayMenu()
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
void Chess::boardFlip() //changes board to and from test mode
{
	board.setTest(!board.getTest());
	cout << board;
}

void Chess::readGame()
{
	;
}
void Chess::displayHelp()
{
	Position pos;
	cout << "Which piece would you like to find the moves for?";
	cin >> pos;
	board[pos].setValidMoveList();
        board[pos].getValidMoveList();
//	if (board[pos].getValidMoveList()[0] == '\0')
//		cout << "No Valid Moves\n";
//	else
//		cout << board[pos].getValidMoveList();
}

void Chess::makeMove()
{
	move1 = userInput;
	this->checkSameColor(); //check that the move piece matches the turn
	if (getIsSameColor())
	{
           board[move1.getSrc()].setValidMoveList();
           if(board[move1.getSrc()].validateMove(move1.getDes()))
           {
		board.makeMove(move1.getDes(), board[move1.getSrc()]);  //put pieces from source into destination 
		board[move1.getSrc()].setPos(move1.getDes());
		board.makeMove(move1.getSrc(), emptyPiece); // put empty piece where the moving piece came
		this->setPrompt();
		cout << board;
           }
           else
              cout << "mistake";
	}
	else
		cout << "Wait your turn!\n";
}

void Chess::checkSameColor()
{
	if ((playerPrompt == WHITEPLAYER && board[move1.getSrc()].getIsWhite() == true) ||
		(playerPrompt == BLACKPLAYER && board[move1.getSrc()].getIsWhite() == false))
		setIsSameColor(true);
	else
		setIsSameColor(false);
}
void Chess::setPrompt() 
{
        
   if(playerPrompt == WHITEPLAYER)
      playerPrompt = BLACKPLAYER;
   else
      playerPrompt = WHITEPLAYER;
   
 
}

ostream & operator << (ostream & out,  Chess & rhs) 
{
   rhs.getUserInput();
   rhs.pickMenuOption();
   rhs.processInput();
   //rhs.displayMenu();
   
   return out;
}

/**********************************************************************
 * MAIN: This is a driver program for our various piece classes.
 *       You are not allowed to change MAIN in any way
 ***********************************************************************/
int main()
{
   Board board;
   Chess game;

   cout << board;
   while (!game.getQuitGame())
   {
	   
	   cout << game;
   }

   return 0;
}