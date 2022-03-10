#include <iostream>
#include <algorithm>

#include "Board.hpp"

Board::Board(){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      solution[i][j] = 0;
      board[i][j] = 0;
    }
  }
}

// checks if row contains the target
bool Board::rowContains(int board[9][9], int row, int target){
    for(int i = 0; i < 9; i++){
        if(board[row][i] != 0 && board[row][i] == target){
            return true;
        }
    }

    return false;
}

// checks if the column contains the target
bool Board::columnContains(int board[9][9], int col, int target){
    for(int i = 0; i < 9; i++){
        if(board[i][col] != 0 && board[i][col] == target){
            return true;
        }
    }

    return false;
}

// checks if the box contains the target
bool Board::boxContains(int board[9][9], int row, int col, int target){
    int i = row - row % 3;
		int j = col - col % 3;

    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3; b++){
            if(board[i + a][j + b] != 0 && board[i + a][j + b] == target){
                return true;
            }
        }
    }

    return false;
}

bool Board::validPosition(int board[9][9], int row, int col, int guess){
  if(!rowContains(board, row, guess) &&
     !columnContains(board, col, guess) &&
     !boxContains(board, row, col, guess)){
    return true;
  }
  return false;
}

int Board::findSolution(int board[9][9], int row, int col, int count){
  if(row == 8 && col == 9){
    // end of board reached, solution has been found
    return count + 1;
  }
  if(col == 9){
    // end of row, start again at next row
    return findSolution(board, row+1, 0, count);
  }
  if(board[row][col] != 0){
    // given number, move on
    return findSolution(board, row, col+1, count);
  }

  for(int guess = 1; guess <= 9; guess++){
    if(validPosition(board, row, col, guess)){
      // guess does not conflict with board, try it
      board[row][col] = guess;
      if(findSolution(board, row, col+1, count) == count+1){
        // solution has been found
        count++;
        if(!foundSolution){
          // keep track of solution board
          std::copy(&(board[0][0]), &(board[0][0]) + 81, &(solution[0][0]));
          foundSolution = true;
        }
        if(count > 1){
          // stop if more than 1 solution
          return count;
        }
      }
    }
    // erase guess if it is wrong
    board[row][col] = 0;
  }
  // No more moves to make
  return count;
}

void Board::solve(){
  int b[9][9];
  std::copy(&(this->board[0][0]), &(this->board[0][0]) + 81, &b[0][0]);
  findSolution(b, 0, 0);
}

void Board::generateGame(){

}

void Board::print(int board[9][9]){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      std::cout << board[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Board::printBoard(){
  print(board);
}

void Board::printSolution(){
  print(solution);
}
