/* 
 * File:   menu.h
 * Author: Jeffry Simpson
 *
 * Created on July 1, 2015, 7:55 AM
 */

#ifndef MENU_H
#define	MENU_H

#include <iostream>
#include <string>
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
};


#define WHITEPLAYER "(White): "
#define BLACKPLAYER "(Black): "



class Menu {
public:
    Menu();
    Menu(const Menu & orig);
    virtual ~Menu();
    
    void displayMenu();
    void displayHelp();
	void boardFlip();
    void getUserInput();
	void leaveGame();
	void readGame();
	void makeMove();
	void checkSameColor();
	int getMenuOption()							{ return menuOption; }
	void setQuitGame(bool quit)					{ quitGame = quit; }
	bool getQuitGame()							{ return quitGame; }
	void setIsSameColor(bool setColor)			{ isSameColor = setColor; }
	bool getIsSameColor()						{ return isSameColor; }

    friend ostream & operator << (ostream & out, Menu & rhs);
    
    bool operator == (const Menu & rhs) const
    {
        return (playerPrompt == rhs.playerPrompt);
    }
       
    Menu & operator = (const Menu & rhs)
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

    
    string getPrompt() const {return playerPrompt;};
    void setPrompt() ;
    void processInput() ;
    void pickMenuOption();
   
};

#endif	/* MENU_H */

