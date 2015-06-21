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
#a.out : chess.o chessdriver.o 
#	g++ -o chess chess.o chessdriver.o
#	tar -cf project3.tar *.cpp *.h makefile
	

 chess : chess.o position.o move.o chessdriver.o 
	g++ -o chess chess.o position.o move.o chessdriver.o



###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    uiTest.o      Driver program for uiDraw and uiTest
#    pong.o        Only the greatest game ever! (and it was for 20 years)  
###############################################################

chessdriver.o : chessdriver.cpp chess.h
	g++ -c chessdriver.cpp
	
move.o : move.cpp move.h
	g++ -c move.cpp

postion.o : position.cpp position.h
	g++ -c position.cpp

chess.o : chess.cpp chess.h
	g++ -c chess.cpp



###############################################################
# General rules
###############################################################
clean :
	rm a.out *.o *.tar

all :  chess

