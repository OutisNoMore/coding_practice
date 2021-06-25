#include <string>

#include "screen.hpp"

/*********************************************
 * FUNCTION init()
 * -------------------------------------------
 * ACCESOR; This function creates a new Sudoku
 *          game.
 * -------------------------------------------
 * 	Pre-Conditions
 *  	None
 * -------------------------------------------
 * 	Post-Conditions
 * 		A new game of traditional 9x9 Sudoku is
 * 		created.
 ********************************************/
void screen::init(){
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	printScreen();
	cursor();

	exit();
}

/*********************************************
 * FUNCTION exit()
 * -------------------------------------------
 * ACCESOR; This function clears the screen
 * 					of any characters.
 * -------------------------------------------
 * 	Pre-Conditions
 *  	None
 * -------------------------------------------
 * 	Post-Conditions
 * 		The terminal is completely cleared.
 ********************************************/
void screen::exit(){
	clrtoeol();
	refresh();
	endwin();
}

/*********************************************
 * FUNCTION printScreen()
 * -------------------------------------------
 * ACCESOR; This function prints a traditional
 *  				9x9 sudoku board onto the terminal.
 * -------------------------------------------
 * 	Pre-Conditions
 *  	None
 * -------------------------------------------
 * 	Post-Conditions
 * 		A new traditional 9x9 Sudoku board is
 * 		created.
 ********************************************/
void screen::printScreen(){
	mvprintw(0, 0,  "-------------------");
	mvprintw(1, 0,  "| | | | | | | | | |");
	mvprintw(2, 0,  "-------------------");
	mvprintw(3, 0,  "| | | | | | | | | |");
	mvprintw(4, 0,  "-------------------");
	mvprintw(5, 0,  "| | | | | | | | | |");
	mvprintw(6, 0,  "-------------------");
	mvprintw(7, 0,  "| | | | | | | | | |");
	mvprintw(8, 0,  "-------------------");
	mvprintw(9, 0,  "| | | | | | | | | |");
	mvprintw(10, 0, "-------------------");
	mvprintw(11, 0, "| | | | | | | | | |");
	mvprintw(12, 0, "-------------------");
	mvprintw(13, 0, "| | | | | | | | | |");
	mvprintw(14, 0, "-------------------");
	mvprintw(15, 0, "| | | | | | | | | |");
	mvprintw(16, 0, "-------------------");
	mvprintw(17, 0, "| | | | | | | | | |");
	mvprintw(18, 0, "-------------------");
}

/*********************************************
 * FUNCTION cursor()
 * -------------------------------------------
 * ACCESOR; This function allows the user to
 * 					move and control the cursor.
 * -------------------------------------------
 * 	Pre-Conditions
 *  	None
 * -------------------------------------------
 * 	Post-Conditions
 * 		The user is able to move an asterisk to
 * 		indicate its position in a 9x9 sudoku 
 * 		board
 ********************************************/
void screen::cursor(){
	int ch = 0;
  const char* cursor = "*";
	bool run = true;

	while(run){
		if(cursor != "*" || mvinch(yPos, xPos) == 32){
			mvprintw(yPos, xPos, cursor);
		} 

		ch = getch();
		if(mvinch(yPos, xPos) == 42){
			mvprintw(yPos, xPos, " ");
		}

		switch(ch){
			case 48:
				cursor = "*";
				break;
			case 49: 			  // 1
				cursor = "1";
				break;
			case 50:        // 2
				cursor = "2";
				break;
			case 51:
				cursor = "3";
				break;
			case 52:
				cursor = "4";
				break;
			case 53:
				cursor = "5";
				break;
			case 54:
				cursor = "6";
				break;
			case 55:
				cursor = "7";
				break;
			case 56:
				cursor = "8";
				break;
			case 57:
				cursor = "9";
				break;
			case KEY_UP:
				yPos -= 2;
				cursor = "*";
				break;
			case KEY_DOWN:
				yPos += 2;
				cursor = "*";
				break;
			case KEY_LEFT:
				xPos -= 2;
				cursor = "*";
				break;
			case KEY_RIGHT:
				xPos += 2;
				cursor = "*";
				break;
			default:
				run = false;
		}

		validatePosition();
	}
}

/*********************************************
 * FUNCTION validatePosition()
 * -------------------------------------------
 * MUTATOR; This function checks the x and y
 *   			 	position of the cursor.
 * -------------------------------------------
 * 	Pre-Conditions
 *  	None
 * -------------------------------------------
 * 	Post-Conditions
 * 		The x and y position of the cursor is 
 * 		ensured to be within the 9x9 board.
 ********************************************/
void screen::validatePosition(){
	if(xPos < 1){
		xPos = 1;
	}
	if(xPos > 17){
		xPos = 17;
	}
	if(yPos > 17){
		yPos = 17;
	}
	if(yPos < 1){
		yPos = 1;
	}
}
