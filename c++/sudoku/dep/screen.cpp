#include "screen.hpp"

screen::screen(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			board[i][j]  = 0;
		}
	}
}

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

	if(!has_colors()){
		throw "Terminal does not support color";
	}
	
	start_color();
	init_pair(RED_ON_BLACK, COLOR_RED, COLOR_BLACK);
	init_pair(WHITE_ON_BLACK, COLOR_WHITE, COLOR_BLACK);

	generateNumbers();
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
 * FUNCTION generateNumbers()
 * -------------------------------------------
 * ACCESOR; This function randomly generates 
 *   	      the numbers used for a game of 
 *   	      sudoku
 * -------------------------------------------
 * 	Pre-Conditions
 *  	None
 * -------------------------------------------
 * 	Post-Conditions
 * 	  Member attribute board is filled with 
 * 	  the given numbers used in the game.
 ********************************************/
void screen::generateNumbers(){

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
	char rows[20];
	int k = 0;

	for(int i = 1; i < 18; i += 2){
		memset(rows, '\0', 20);
    for(int j = 0; j < 19; j++){
			if(j%2 == 0){
				strncat(rows, "|\0", 2);
			} 
			else{
				char c = ' ';
	  	  if(board[(i-1)/2][k] != 0){
					c = board[(i-1)/2][k++] + 48;
		  	}
				strncat(rows, &c, 1);
			}
		}
		rows[19] = '\0';
		mvprintw(i, 0, rows);
	}
	
	mvprintw(0, 0,  "-------------------");
	mvprintw(2, 0,  "-------------------");
	mvprintw(4, 0,  "-------------------");
	mvprintw(6, 0,  "-------------------");
	mvprintw(8, 0,  "-------------------");
	mvprintw(10, 0, "-------------------");
	mvprintw(12, 0, "-------------------");
	mvprintw(14, 0, "-------------------");
	mvprintw(16, 0, "-------------------");
	mvprintw(18, 0, "-------------------");
	mvprintw(yPos, xPos, "*");
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
		if(cursor != "*" || mvinch(yPos, xPos) == 32){ // if cursor is a number
																									 // or cell is empty
			mvprintw(yPos, xPos, cursor);
		}

		ch = getch();
		if(mvinch(yPos, xPos) == 42){ // if cell has an asterisk delete it
			mvprintw(yPos, xPos, " ");
		}

		switch(ch){
			case 48:        // 0
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
				if(validatePosition(xPos, yPos-2)){
					yPos -= 2;
				}
				cursor = "*";
				break;
			case KEY_DOWN:
				if(validatePosition(xPos, yPos+2)){
					yPos += 2;
				}
				cursor = "*";
				break;
			case KEY_LEFT:
				if(validatePosition(xPos-2, yPos)){
					xPos -= 2;
				}
				cursor = "*";
				break;
			case KEY_RIGHT:
				if(validatePosition(xPos+2, yPos)){
					xPos += 2;
				}
				cursor = "*";
				break;
			default:
				run = false;
		}
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
 * 		ensured to be within the 9x9 board and 
 * 		is not occupied by a given number.
 ********************************************/
bool screen::validatePosition(int xPos, int yPos){
	int col = (xPos - 1)/2;
	int row = (yPos - 1)/2;
	// check if there is a constant number
	// at cell position
  if(board[row][col] != 0){
		return false;
	}

	// check that position is not out of bounds
	if(xPos < 1){
	  return false;
	}
	if(xPos > 17){
		return false;
	}
	if(yPos > 17){
		return false;
	}
	if(yPos < 1){
		return false;
	}

	return true;
}
