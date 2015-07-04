###############################################################
# Program:
#    Project 3, Chess            
#    Brother McCracken, CS165
# Author:
#     Jeffry Simpson 50%
#     Samuel Koontz  50%
# Summary:
#     Enter a brief description of your program here! If you do any
#     extra credit, this would be a good place to describe it.
#
#     Estimated:  0.0 hrs
#     Actual:     0.0 hrs
#       Please describe briefly what was the most difficult part
###############################################################

###############################################################
# Programs:
#    pong:         The playable game
#    uiTest:       Simple driver program for the drawing interface
###############################################################

 a.out : piece.o position.o move.o board.o chess.o
	g++ -o chess piece.o position.o move.o board.o chess.o



###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    uiTest.o      Driver program for uiDraw and uiTest
#    pong.o        Only the greatest game ever! (and it was for 20 years)  
###############################################################

#chess.o : chess.cpp piece.h
#	g++ -c chess.cpp
	
board.o : board.cpp board.h
	g++ -c board.cpp
	
piece.o : piece.cpp piece.h
	g++ -c piece.cpp

move.o : move.cpp move.h
	g++ -c move.cpp

postion.o : position.cpp position.h
	g++ -c position.cpp
	
chess.o : chess.cpp chess.h
	g++ -c chess.cpp

moveTest.o : movetest.cpp
	g++ -c moveTest.cpp




###############################################################
# General rules
###############################################################
clean :
	rm a.out *.o *.tar

all :  chess

