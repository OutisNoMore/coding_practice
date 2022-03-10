#include <iostream>
#include <vector>

// checks if row contains the target
bool rowContains(std::vector<std::vector<char>>& board, int row, int target){
    for(int i = 0; i < 9; i++){
        if(board[row][i] != '.' && (board[row][i] - '0') == target){
            return true;
        }
    }

    return false;
}

// checks if the column contains the target
bool columnContains(std::vector<std::vector<char>>& board, int col, int target){
    for(int i = 0; i < 9; i++){
        if(board[i][col] != '.' && (board[i][col] - '0') == target){
            return true;
        }
    }

    return false;
}

// checks if the box contains the target
bool boxContains(std::vector<std::vector<char>>& board, int row, int col, int target){
    int i = row - row % 3;
		int j = col - col % 3;

    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3; b++){
            if(board[i + a][j + b] != '.' && (board[i + a][j + b] - '0') == target){
                return true;
            }
        }
    }

    return false;
}

bool validPosition(std::vector<std::vector<char>>& board, int row, int col, int guess){
  if(!rowContains(board, row, guess) &&
     !columnContains(board, col, guess) &&
     !boxContains(board, row, col, guess)){
    return true;
  }
  return false;
}

bool findSolution(std::vector<std::vector<char>>& board, int row, int col){
  if(row == 8 && col == 9){
    // end of board reached solution has been found
    return true;
  }
  if(col == 9){
    // end of row, start again at next row
    return findSolution(board, row+1, 0);
  }
  if(board[row][col] != '.'){
    // given number, move on
    return findSolution(board, row, col+1);
  }

  for(int guess = 1; guess <= 9; guess++){
    if(validPosition(board, row, col, guess)){
      // guess does not conflict with board, try it
      board[row][col] = (guess + '0');
      if(findSolution(board, row, col+1)){
        return true;
      }
    }
  }
  // No more moves to make
  board[row][col] = '.';
  return false ;
}

void solveSudoku(std::vector<std::vector<char>>& board){
	if(findSolution(board, 0, 0)){
		std::cout << "Solution found!" << std::endl;
	} else{
		std::cout << "No solution" << std::endl;
	}
}

void printBoard(std::vector<std::vector<char>>& board){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(){
  char r1[] = {'5','3','.','.','7','.','.','.','.'};
  char r2[] = {'6','.','.','1','9','5','.','.','.'};
  char r3[] = {'.','9','8','.','.','.','.','6','.'};
  char r4[] = {'8','.','.','.','6','.','.','.','3'};
  char r5[] = {'4','.','.','8','.','3','.','.','1'};
  char r6[] = {'7','.','.','.','2','.','.','.','6'};
  char r7[] = {'.','6','.','.','.','.','2','8','.'};
  char r8[] = {'.','.','.','4','1','9','.','.','5'};
  char r9[] = {'.','.','.','.','8','.','.','7','9'};

  std::vector<char> a(r1, r1 + sizeof(r1)/sizeof(char));
  std::vector<char> b(r2, r2 + sizeof(r2)/sizeof(char));
  std::vector<char> c(r3, r3 + sizeof(r3)/sizeof(char));
  std::vector<char> d(r4, r4 + sizeof(r4)/sizeof(char));
  std::vector<char> e(r5, r5 + sizeof(r5)/sizeof(char));
  std::vector<char> f(r6, r6 + sizeof(r6)/sizeof(char));
  std::vector<char> g(r7, r7 + sizeof(r7)/sizeof(char));
  std::vector<char> h(r8, r8 + sizeof(r8)/sizeof(char));
  std::vector<char> i(r9, r9 + sizeof(r9)/sizeof(char));

  std::vector<std::vector<char>> test;
  test.push_back(a);
  test.push_back(b);
  test.push_back(c);
	test.push_back(d);
	test.push_back(e);
	test.push_back(f);
	test.push_back(g);
	test.push_back(h);
	test.push_back(i);
  printBoard(test);

	solveSudoku(test);

	printBoard(test);

  return 0;
}
