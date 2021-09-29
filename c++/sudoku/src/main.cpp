#include <iostream>

#include <ncurses.h>

#include "../dep/screen.hpp"

int setDifficulty();

int main(){
	int difficulty = -1;

	difficulty = setDifficulty();
	screen sudoku;
	sudoku.init(difficulty);

	return 0;
}

int setDifficulty(){
	char difficulty;

	std::cout << "-----------SUDOKU--------------\n"
						<< "Please Choose a Difficulty (Hard, Medium, or Easy): ";
	std::cin  >> difficulty;
	std::cout << std::endl;

	switch(difficulty){
		case 'H':
			return 0;
		case 'M':
			return 1;
		case 'E':
			return 2;
	}

	return -1;
}
