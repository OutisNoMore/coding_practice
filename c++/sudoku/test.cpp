#include <iostream>

#include "ncurses.h"

int main(){
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	mvprintw(0, 0, "1");
	if(mvinch(0, 0) == 49){
		std::cout << "Yes" << std::endl;
	}

	if(getch() == KEY_UP){
	clrtoeol();
	refresh();
	endwin();
	}

	return 0;
}
