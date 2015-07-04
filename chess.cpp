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
#include <fstream>
#include <cstring>

using namespace std;

Chess::Chess() : playerPrompt(WHITEPLAYER) { setQuitGame(false); }
Chess::Chess(const Chess& orig) { }
Chess::~Chess() { }

Board board;
char boardLetter[8][8];
Move move1;
Space emptyPiece(true, 0, 0);  //Create an empty Space piece to put in Dest
string MoveList;
string allMoves;

void Chess::setBoardLetter(Position pos1)
{

	for (int i = 7; i >= 0; i--)
		for (int j = 0; j < 8; j++)
		{
			Position posTemp;
			posTemp.set(i, j);
			board[pos1].setBoardLetters(i, j, board[posTemp].getLetter());
			//boardLetter[i][j] = board[posTemp].getLetter();
		}
}
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
		  this->readGame();
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
   char fileName[256];
   char line[25];  
  
   cin.getline( line, 25, '\n' );
   cout << "To save a game, please specify the filename.\n";
   cout << "    To quit without saving a file, just press <enter>\n";

   cin.getline( fileName, 256);
  
   ofstream out(fileName);
   out << allMoves;
   out.close();
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
	Move readMove;
	string temp;
	string tempMove;
	char fileName[256];
	cout << "Filename: ";
	cin >> fileName;

	ifstream fin(fileName);
	if (fin.fail())
	{
		cout << "Unable to open file";
		return;
	}
	while (fin>>temp)
	{
		readMove = temp;
		board.makeMove(readMove.getDes(), board[readMove.getSrc()]);  //put pieces from source into destination 
		board[readMove.getSrc()].setPos(readMove.getDes());
		board.makeMove(readMove.getSrc(), emptyPiece); // put empty piece where the moving piece came
	}
	cout << board;
}
void Chess::displayHelp()
{
	Position pos;
	cout << "Which piece would you like to find the moves for?";
	cin >> pos;
	setBoardLetter(pos);
	board[pos].legalMoves = "";
	board[pos].setValidMoveList();
	cout << "Possible moves are:\n" << board[pos].legalMoves;

}


void Chess::makeMove()
{
   Position pos;
         move1 = userInput;
           
	this->checkSameColor(); //check that the move piece matches the turn
	if (getIsSameColor())
	{
           board[move1.getSrc()].legalMoves = "";
           board[move1.getSrc()].setValidMoveList();
       
           if(checkValidMove(board[move1.getSrc()].getPos(),move1))
              cout << "Valid";
              
		board.makeMove(move1.getDes(), board[move1.getSrc()]);  //put pieces from source into destination 
		board[move1.getSrc()].setPos(move1.getDes());
		board.makeMove(move1.getSrc(), emptyPiece); // put empty piece where the moving piece came
		writeMoves(move1);
                //board[move1.getSrc()].setMoved();
                this->setPrompt();
		cout << board;
                cout << board[move1.getSrc()].legalMoves;
	}
	else
		cout << "Wait your turn!\n";
}

bool Chess::checkValidMove(Position pos, Move move)
{
   std::size_t xyz;
   //string temp = move.getText();
   string  temp = "d1d4";
   string temp2 = "d7d6\nd1d5\ne2e3\nd1d4\n";
  // board[pos].legalMoves = "";
   //board[pos].setValidMoveList();
   //xyz = board[pos].legalMoves.find(temp);
     cout << temp2.find(temp);     
//   cout<< "Temp: " << temp <<endl;
//   cout << "XXX "<< board[pos].legalMoves << "xxx";
   if(xyz > 0)
   {
      cout << "XXValid move " << xyz << "<-";
            return true;
   }

   else
    {
      cout << "YYInvalid move " << xyz << "<-";
            return false;
   }

   
}

void Chess::writeMoves(Move move)
{
   allMoves += move.getText();
   if(playerPrompt == WHITEPLAYER)
      allMoves += " ";
   else
      allMoves += "\n";
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

	if (playerPrompt == WHITEPLAYER)
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