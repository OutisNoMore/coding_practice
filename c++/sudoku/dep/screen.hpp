#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <cstring>

#include <ncurses.h>

#define RED_ON_BLACK   1
#define WHITE_ON_BLACK 2

class screen{
	private:
		int board[9][9];   // 9x9 board for sudoku
		int xPos = 1;      // x position of cursor
		int yPos = 3;      // y position of cursor
	
	public:
		screen();
		void init();
		void exit();

		void generateNumbers();
		void printScreen();
		void cursor();
		bool validatePosition(int xPos, int yPos);
};

#endif // SCREEN_HPP

/***************************************************
 * screen class
 *
 * -------------------------------------------------
 *  This class prints the board for a terminal 
 *  based game of sudoku. The class keeps track of 
 *  the board using a 2-dimensional int matrix
 *  and the x and y position of the cursor relative
 *  to the board.
 ***************************************************/
