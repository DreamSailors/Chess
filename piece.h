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


#ifndef PIECE_H
#define	PIECE_H
#define MAC


#include <iostream>
#include <cassert>
#include <string>
#include "move.h"
#include "position.h"


using namespace std;

#define WHITE_WHITE "\E[31;47m " // white square white piece
#define WHITE_BLACK "\E[30;47m " // white square black piece
#define BLACK_WHITE "\E[37;41m " // black square white piece
#define BLACK_BLACK "\E[30;41m " // black square black piece
#define NONE        " \E[0m"     // setback to normal colors



/*****************************************
 * PIECE
 * The base piece class.  
 * 
 *****************************************/
class Piece 
{
public:
	
   Piece(bool isWhite, int row, int col) : isWhite(isWhite), position(row, col), moved(false) { setValidMoveList(); }
   virtual ~Piece() { }
   bool getIsWhite() const          { return isWhite; }
   bool hasMoved()   const          {return moved; }
   virtual char getLetter() const  = 0;
   virtual int getScore() const = 0;
   
   //string getValidMoveList() { return validMoveList; }
   friend ostream & operator << (ostream & out, const Piece & rhs);
   Position getPos()         { return this->position; }
   virtual void setValidMoveList() { /*validMoveList = '\0';*/ };
   virtual void setPos(Position pos) { this->position = pos; };
   //Position possibleMoveArray[0][0];
   virtual bool validateMove(Position pos) {return false;};
   virtual void getValidMoveList() {};
   
   
protected:
    Position position;
    string validMovelist;
    bool moved;
    bool isWhite;
    void setMove(bool moved) {this->moved = moved;};


	
};

class Space : public Piece
{
public:
   Space(bool isWhite, int row, int col) : Piece(isWhite, row , col)   
   { };
   virtual int getScore() const    { return 0;}
   virtual char getLetter() const  { return PIECE_EMPTY;}
   
};

class King : public Piece
{
public:
	King(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
	{ };
	Position possibleMoveArray[8][1];
	virtual int getScore() const    { return getIsWhite() ? 1000 : -1000; }
	virtual char getLetter() const  { return getIsWhite() ? 'k' : 'K'; }
        bool validateMove(Position pos);
        void getValidMoveList();
        void setValidMoveList();
 };

class Queen : public Piece
{
   public:
      Queen(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
      { };

      Position possibleMoveArray[7][7];
      virtual int getScore() const    { return getIsWhite() ? 9: -9;}
      virtual char getLetter() const  { return getIsWhite() ? 'q' : 'Q';}
      
   /**************************************************************
    * ValidateMove
    *    Given a piece location determines if it is a valid move
    *************************************************************/
        bool validateMove(Position pos)
        {
            bool valid = false;
            
		for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 7; j++)
                    if (possibleMoveArray[i][j].isValid())
                        if(pos == possibleMoveArray[i][j])
                        {
                            valid = true;
                            break;
                        }                    
            
            return(valid);
        }
 
    /**************************************************************
    * getValidMoveList
    * Given a piece location displays all valid moves
    *************************************************************/
        void getValidMoveList()
        {  
		  for (int i = 0; i < 8; i++)
                     for (int j = 0; j < 7; j++)
                        if (possibleMoveArray[i][j].isValid())
                            cout << possibleMoveArray[i][j] << endl;   
                                   
         }
 
    /**************************************************************
    * setValidMoveList
    * Given a piece location displays all possible moves
    *************************************************************/
      void setValidMoveList()
	  {
#ifdef MAC

		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[0][i] = this->getPos() += (Delta){0, i + 1};//RIGHT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[1][i] = this->getPos() += (Delta){i + 1, i + 1};//UP and RIGHT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[2][i] = this->getPos() += (Delta){i + 1, 0}; //UP
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[3][i] = this->getPos() += (Delta){i + 1, -i - 1}; //UP and LEFT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[4][i] = this->getPos() += (Delta){0, -i - 1}; // LEFT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[5][i] = this->getPos() += (Delta){-i - 1, -i - 1};//DOWN and LEFT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[6][i] = this->getPos() += (Delta){-i - 1, 0}; //DOWN
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[7][i] = this->getPos() += (Delta){-i - 1, i + 1}; //DOWN and RIGHT
#else
 		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[0][i] = this->getPos() += {0, 1 + 1};//RIGHT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[1][i] = this->getPos() += {i + 1, i + 1};//UP and RIGHT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[2][i] = this->getPos() += {i + 1, 0}; //UP
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[3][i] = this->getPos() += {i + 1, -i - 1}; //UP and LEFT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[4][i] = this->getPos() += {0, -i - 1}; // LEFT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[5][i] = this->getPos() += {-i - 1, -i - 1};//DOWN and LEFT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[6][i] = this->getPos() += {-i - 1, 0}; //DOWN
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[7][i] = this->getPos() += {-i - 1, i + 1}; //DOWN and RIGHT                         
#endif

		  for (int i = 0; i < 8; i++)
		  {
			  for (int j = 0; j < 7; j++)
				  cout << possibleMoveArray[i][j] << " isValid: " << possibleMoveArray[i][j].isValid() << endl;
			  cout << endl;
		  }
	  }
};

class Pawn : public Piece
{
   public:
     Pawn(const bool isWhite, int row, int col) : Piece(isWhite,row,col)
      { };
	 Position(possibleMoveArray[2][3]);
     virtual int getScore() const    { return getIsWhite() ? 1: -1;}
     virtual char getLetter() const  { return getIsWhite() ? 'p' : 'P';}
     
     /**************************************************************
    * ValidateMove
    * Given a piece location determines if it is a valid move
    *************************************************************/
        bool validateMove(Position pos)
        {
            bool valid = false;
            
		for (int i = 0; i < 2; i++)
                    for (int j = 0; j < 3; j++)
                    if (possibleMoveArray[i][j].isValid())
                        if(pos == possibleMoveArray[i][j])
                        {
                            valid = true;
                            break;
                        }                    
            
            return(valid);
        }
 
    /**************************************************************
    * getValidMoveList
    * Given a piece location displays all valid moves
    *************************************************************/
        void getValidMoveList()
        {  
		  for (int i = 0; i < 2; i++)
                     for (int j = 0; j < 3; j++)
                        if (possibleMoveArray[i][j].isValid())
                            cout << possibleMoveArray[i][j] << endl;   
                                   
         }
 
    /**************************************************************
    * setValidMoveList
    * Given a piece location displays all possible moves
    *************************************************************/
	 void setValidMoveList()
	 {
		 int direction = 0;
		 if (isWhite)
			 direction = 1;
		 else
			 direction = -1;
#ifdef MAC
		 possibleMoveArray[0][0] = this->getPos() += (Delta){direction, 1};// Up and right
		 possibleMoveArray[0][1] = this->getPos() += (Delta){direction, 0};//Up
		 possibleMoveArray[0][2] = this->getPos() += (Delta){direction, -1};//Up and left
		 possibleMoveArray[1][1].setInvalid();
		 possibleMoveArray[1][2].setInvalid();
		 if (!moved)
		 {
			 possibleMoveArray[1][0] = this->getPos() += (Delta){(direction * 2), 0};//move 2 spaces if first move
		 }
		 else
			 possibleMoveArray[1][0].setInvalid();                 
#else
 		 possibleMoveArray[0][0] = this->getPos() += {direction, 1};// Up and right
		 possibleMoveArray[0][1] = this->getPos() += {direction, 0};//Up
		 possibleMoveArray[0][2] = this->getPos() += {direction, -1};//Up and left
		 possibleMoveArray[1][1].setInvalid();
		 possibleMoveArray[1][2].setInvalid();
		 if (!moved)
		 {
			 possibleMoveArray[1][0] = this->getPos() += {(direction * 2), 0};//move 2 spaces if first move
		 }
		 else
			 possibleMoveArray[1][0].setInvalid();                
#endif

		 cout << "pos" << this->position << endl;
		 for (int i = 0; i < 2; i++)
		 {
			 for (int j = 0; j < 3; j++)
				 cout << possibleMoveArray[i][j] << " isValid: " << possibleMoveArray[i][j].isValid() << endl;
			 cout << endl;
		 }
			 
	 }
};

class Rook : public Piece
{
public:
      Rook(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
      { };
	  Position possibleMoveArray[3][7];
      virtual int getScore() const    { return getIsWhite() ? 5: -5;}
      virtual char getLetter() const  { return getIsWhite() ? 'r' : 'R';}
      
   /**************************************************************
    * ValidateMove
    * Given a piece location determines if it is a valid move
    *************************************************************/
        bool validateMove(Position pos)
        {
            bool valid = false;
            
		for (int i = 0; i < 4; i++)		 
                    for (int j = 0; j < 7; j ++)
                    if (possibleMoveArray[i][j].isValid())
                        if(pos == possibleMoveArray[i][j])
                        {
                            valid = true;
                            break;
                        }                    
            
            return(valid);
        }
 
    /**************************************************************
    * getValidMoveList
    * Given a piece location displays all valid moves
    *************************************************************/
        void getValidMoveList()
        {  
		for (int i = 0; i < 4; i++)		 
                    for (int j = 0; j < 7; j ++)
                        if (possibleMoveArray[i][j].isValid())
                            cout << possibleMoveArray[i][j] << endl;   
                               	           
         }
 
    /**************************************************************
    * setValidMoveList
    * Given a piece location displays all possible moves
    *************************************************************/      
	  void setValidMoveList()
	  {
#ifdef MAC             
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[0][i] = this->getPos() += (Delta){0, i +1};//RIGHT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[1][i] = this->getPos() += (Delta){i + 1, 0}; //UP
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[2][i] = this->getPos() += (Delta){0, -i - 1}; // LEFT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[3][i] = this->getPos() += (Delta){-i - 1, 0}; //DOWN
#else
                  for (int i = 0; i < 7; i++)
			  possibleMoveArray[0][i] = this->getPos() += {0, i +1};//RIGHT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[1][i] = this->getPos() += {i + 1, 0}; //UP
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[2][i] = this->getPos() += {0, -i - 1}; // LEFT
		  for (int i = 0; i < 7; i++)
			  possibleMoveArray[3][i] = this->getPos() += {-i - 1, 0}; //DOWN
#endif

		  for (int i = 0; i < 4; i++)
		  {
			  for (int j = 0; j < 7; j ++)
			  cout << possibleMoveArray[i][j] << " isValid: " << possibleMoveArray[i][j].isValid() << endl;
			  cout << endl;
		  }
	  }
};

class Knight : public Piece
{
   public:
      Knight(const bool isWhite, int row, int col) : Piece(isWhite, row,col)
      { };
	  Position possibleMoveArray[8][1];
      virtual int getScore() const    { return getIsWhite() ? 3: -3;}
      virtual char getLetter() const  { return getIsWhite() ? 'n' : 'N';}
      
        /**************************************************************
    * ValidateMove
    * Given a piece location determines if it is a valid move
    *************************************************************/
        bool validateMove(Position pos)
        {
            bool valid = false;
            
            for (int i = 0; i < 7; i++)
                if (possibleMoveArray[i][0].isValid())
                    if(pos == possibleMoveArray[i][0])
                    {
                        valid = true;
                        break;
                    }                    

            return(valid);
        }
 
    /**************************************************************
    * getValidMoveList
    * Given a piece location displays all valid moves
    *************************************************************/
        void getValidMoveList()
        {  
            for (int i = 0; i < 7; i++)
                if (possibleMoveArray[i][0].isValid())
                    cout << possibleMoveArray[i][0] << endl;   
                               	           
         }
 
    /**************************************************************
    * setValidMoveList
    * Given a piece location displays all possible moves
    *************************************************************/      
	  void setValidMoveList()
	  {
#ifdef MAC
		  possibleMoveArray[0][0] = this->getPos() += (Delta){1, 2}; //up one, right 2
		  possibleMoveArray[1][0] = this->getPos() += (Delta){2, 1}; //up two, right 1
		  possibleMoveArray[2][0] = this->getPos() += (Delta){1, -2}; //up one, left 2
		  possibleMoveArray[3][0] = this->getPos() += (Delta){2, -1}; //up two, left 1
		  possibleMoveArray[4][0] = this->getPos() += (Delta){-1, 2}; //down one, right 2
		  possibleMoveArray[5][0] = this->getPos() += (Delta){-2, 1}; //down two, right 1
		  possibleMoveArray[6][0] = this->getPos() += (Delta){-1, -2}; //down one, left 2
		  possibleMoveArray[7][0] = this->getPos() += (Delta){-2, -1}; //down two, left 1
#else
		  possibleMoveArray[0][0] = this->getPos() += {1, 2}; //up one, right 2
		  possibleMoveArray[1][0] = this->getPos() += {2, 1}; //up two, right 1
		  possibleMoveArray[2][0] = this->getPos() += {1, -2}; //up one, left 2
		  possibleMoveArray[3][0] = this->getPos() += {2, -1}; //up two, left 1
		  possibleMoveArray[4][0] = this->getPos() += {-1, 2}; //down one, right 2
		  possibleMoveArray[5][0] = this->getPos() += {-2, 1}; //down two, right 1
		  possibleMoveArray[6][0] = this->getPos() += {-1, -2}; //down one, left 2
		  possibleMoveArray[7][0] = this->getPos() += {-2, -1}; //down two, left 1
#endif


		  cout << this->getPos();
		  for (int i = 0; i < 7; i++)
		  {
			  cout << possibleMoveArray[i][0] << " isValid: " << possibleMoveArray[i][0].isValid() << endl;
		  }
	  }
   
};

class Bishop : public Piece
{
   public:
     Bishop(const bool isWhite, int row, int col) : Piece(isWhite, row, col)
      { };
	 Position possibleMoveArray[3][7];
     virtual int getScore() const    { return getIsWhite() ? 3: -3;}
     virtual char getLetter() const  { return getIsWhite() ? 'b' : 'B';}
     /**************************************************************
    * ValidateMove
    * Given a piece location determines if it is a valid move
    *************************************************************/
        bool validateMove(Position pos)
        {
            bool valid = false;
            
		for (int i = 0; i < 4; i++)		 
                    for (int j = 0; j < 7; j ++)
                    if (possibleMoveArray[i][j].isValid())
                        if(pos == possibleMoveArray[i][j])
                        {
                            valid = true;
                            break;
                        }                    
            
            return(valid);
        }
 
    /**************************************************************
    * getValidMoveList
    * Given a piece location displays all valid moves
    *************************************************************/
        void getValidMoveList()
        {  
		for (int i = 0; i < 4; i++)		 
                    for (int j = 0; j < 7; j ++)
                        if (possibleMoveArray[i][j].isValid())
                            cout << possibleMoveArray[i][j] << endl;   
                               	           
         }
 
    /**************************************************************
    * setValidMoveList
    * Given a piece location displays all possible moves
    *************************************************************/      
	 void setValidMoveList()
	 {
#ifdef MAC
		 for (int i = 0; i < 7; i++)
			 possibleMoveArray[0][i] = this->getPos() += (Delta){i + 1, i + 1};//UP and RIGHT
		 for (int i = 0; i < 7; i++)
			 possibleMoveArray[1][i] = this->getPos() += (Delta){i + 1, -i - 1}; //UP and LEFT
		 for (int i = 0; i < 7; i++)
			 possibleMoveArray[2][i] = this->getPos() += (Delta){-i - 1, -i - 1};//DOWN and LEFT
		 for (int i = 0; i < 7; i++)
			 possibleMoveArray[3][i] = this->getPos() += (Delta){-i - 1, i + 1}; //DOWN and RIGHT
#else
  		 for (int i = 0; i < 7; i++)
			 possibleMoveArray[0][i] = this->getPos() += {i + 1, i + 1};//UP and RIGHT
		 for (int i = 0; i < 7; i++)
			 possibleMoveArray[1][i] = this->getPos() += {i + 1, -i - 1}; //UP and LEFT
		 for (int i = 0; i < 7; i++)
			 possibleMoveArray[2][i] = this->getPos() += {-i - 1, -i - 1};//DOWN and LEFT
		 for (int i = 0; i < 7; i++)
			 possibleMoveArray[3][i] = this->getPos() += {-i - 1, i + 1}; //DOWN and RIGH                       
#endif 

		 for (int i = 0; i < 4; i++)
		 {
			 for (int j = 0; j < 7; j++)
				 cout << possibleMoveArray[i][j] << " isValid: " << possibleMoveArray[i][j].isValid() << endl;
			 cout << endl;
		 }
	 }
};


#endif	/* PIECE.H */

