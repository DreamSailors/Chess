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

#include "piece.h"
#include "board.h"


//Board board;
/*********************************************
 * OUT << PIECE
 * Insertion operator for the piece
 ********************************************/
ostream & operator << (ostream & out, const Piece & rhs)
{
   out << rhs.getLetter();
   return out;
}

       
    /**************************************************************
    * ValidateMove
    * Given a piece location determines if it is a valid move
    *************************************************************/
bool King::validateMove(Position pos)
{
   bool valid = false;

     for (int i = 0; i < 8; i++)
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
void King::getValidMoveList()
{

   cout << "Possible moves are:\n" ;
     for (int i = 0; i < 8; i++)
       {
           if (possibleMoveArray[i][0].isValid())
           {
              
              cout << "\t"<< this->getPos()  << possibleMoveArray[i][0] << endl; 
           }
               

       }

}
        
/**************************************************************
* setValidMoveList
* Given a piece location displays all possible moves
*************************************************************/
  void King::setValidMoveList()
  {
          possibleMoveArray[0][0] = this->getPos() += RIGHT;
          possibleMoveArray[1][0] = this->getPos() += UP_RIGHT;
          possibleMoveArray[2][0] = this->getPos() += UP;
          possibleMoveArray[3][0] = this->getPos() += UP_LEFT;
          possibleMoveArray[4][0] = this->getPos() += LEFT;
          possibleMoveArray[5][0] = this->getPos() += DOWN_LEFT;
          possibleMoveArray[6][0] = this->getPos() += DOWN;
          possibleMoveArray[7][0] = this->getPos() += DOWN_RIGHT;

#ifdef DEBUG          
          cout << this->getPos();
          for (int i = 0; i < 8; i++)
          {
                  cout << possibleMoveArray[i][0] << " isValid: " << possibleMoveArray[i][0].isValid() << endl;
          }
#endif
  }


