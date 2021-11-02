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

    for(int a = 0; a < 3; a++, i++){
        for(int b = 0; b < 3; b++, j++){
            if(board[i][j] != '.' && (board[i][j] - '0') == target){
                return true;
            }
        }
    }

    return false;
}

bool findSolution(std::vector<std::vector<char>>& board, int row, int col){
	if(row == 8 && col == 9){
		return true;
	}
	if(col == 9){
		row++;
		col = 0;
//		return findSolution(board, row, col);
	}

	if(board[row][col] != '.'){
	  return findSolution(board, row, col + 1);
	}

	for(int i = 1; i <= 9; i++){ 
		if(!rowContains(board, row, i)    &&
			 !columnContains(board, col, i) &&
			 !boxContains(board, row, col, i)){
			board[row][col] = (i + '0');

			return findSolution(board, row, col+1);
		}
	}

	return false;
}

void solveSudoku(std::vector<std::vector<char>>& board){
	if(findSolution(board, 0, 0)){
		std::cout << "Solution found!" << std::endl;
	} else{
		std::cout << "No solution" << std::endl;
	}
}

/*
// uses back-tracking to solve sudoku puzzle
void solveSudoku(std::vector<std::vector<char>>& board) {     
    int row = 0;
    int col = 0;
    int guess = 1; // from 1 to 9

    while(true){
        //if(row == 8 && col = 9){ // end of board reached, stop program
				if(row == 9){
            break;
        }
        if(col == 9){ // end of row, move to next row
            row++;
            col = 0;
        }

        if(board[row][col] != '.'){ // skip all given numbers
            col++;
            continue;
        }

				// Out of guesses, so need to backtrack
        if(guess == 10){
					guess = 1;
          if(col == 0){
              row--;
              col = 8;
          } else{
              col--;
          }
          // guess = (board[row][col] - '0') + 1; // bad because might be a given number at board[row][col]
          board[row][col] = '.';
          continue;
        }

        board[row][col] = (guess + '0'); // make a guess

				// if the guess conflicts with a given number, try again
        if(rowContains(board, row, guess)    ||
           columnContains(board, col, guess) ||
           boxContains(board, row, col, guess)){
            board[row][col] = '.';
            guess++;
            continue;
        }
        col++;
    }
		
}
*/

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

	solveSudoku(test);

	printBoard(test);

  return 0;
}
