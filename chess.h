/***********************************************************************
* Program:
*    Project 3, Chess            
*    Brother McCracken, CS165
* Author:
*    Jeffry Simpson, Samuel Koontz
* Summary: 
*    Chess headerfile
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/


#ifndef CHESS_H
#define	CHESS_H

#include <cstdlib>
#include <iostream>    // for CIN and COUT
#include <string>
#include <fstream>
#include "position.h"
#include "piece.h"
#include "move.h"
#include "board.h"


using namespace std;

/**************************************
 * MenuOpt
 * Used for menu options
 *************************************/
enum MenuOpt {
   QUIT,
   QUESTION,
   HELP,
   READ,
   TEST,
   MOVE,
   RANK,
   UNKNOWN
};


#define WHITEPLAYER "(White): "
#define BLACKPLAYER "(Black): "



class Chess {
public:
    Chess();
    Chess(const Chess & orig);
    virtual ~Chess();
    string allMoves;
    
    friend ostream & operator << (ostream & out, Chess & rhs);
    
    bool getQuitGame()			{ return quitGame; } 
    bool operator == (const Chess & rhs) const
    {
        return (playerPrompt == rhs.playerPrompt);
    }
       
    Chess & operator = (const Chess & rhs)
    {
        playerPrompt = rhs.playerPrompt;
        return *this;
    };
    
    
        
private:
    string playerPrompt;
    string userInput;
    int menuOption;
	bool quitGame;
	bool isSameColor;

    
    void    setPrompt() ;
    void    processInput() ;
    void    pickMenuOption();
    void    displayMenu();
    void    displayHelp();
    void    boardFlip();
    void    getUserInput();
    void    leaveGame();
    void    readGame();
    void    makeMove();
    void    writeMoves(Move move);
    void    checkSameColor();
    void    setBoardLetter(Position pos1);
    void    setQuitGame(bool quit)          { quitGame = quit; }
    void    setIsSameColor(bool setColor)   { isSameColor = setColor; }
    int     getMenuOption()                 { return menuOption; }
    bool    getIsSameColor()                { return isSameColor; }
    string  getPrompt() const               {return playerPrompt;};
    bool checkValidMove(Position pos, Move move);
    void writeMoves(Move move);
  
};

#endif	/* MENU_H */

