#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <ncurses.h>

class screen{
	private:
		int board[9][9]; // 9x9 board for sudoku
		int xPos = 1;    // x position of cursor
		int yPos = 1;    // y position of cursor
	
	public:
		void init();
		void exit();

		void printScreen();
		void cursor();
		void validatePosition();
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
