#include <iostream>
#include <vector>

// check if row exceeds 45 or full row
bool checkRow(std::vector<std::vector<char>>& board, int row){
    int sum = 0;

    for(int i = 0; i < 9; i++){
        if(board[row][i] != '.'){
            sum += (board[row][i] - '0');
        }
    }

    return sum >= 45;
}

// checks if row contains the target
bool rowContains(std::vector<std::vector<char>>& board, int row, int target){
    for(int i = 0; i < 9; i++){
        if(board[row][i] != '.' && (board[row][i] - '0') == target){
            return true;
        }
    }

    return false;
}

// checks if the column exceeds 45 or a full column
bool checkColumn(std::vector<std::vector<char>>& board, int col){
    int sum = 0;

    for(int j = 0; j < 9; j++){
        if(board[j][col] != '.'){
            sum += (board[j][col] - '0');
        }
    }

    return sum >= 45;
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

// checks if the box exceeds 45 or a full box
bool checkBox(std::vector<std::vector<char>>& board, int row, int col){
    int i, j;

    if(row < 3){
        i = 0;
    } else if(row < 6){
        i = 3;
    } else{
        i = 6;
    }

    if(col < 3){
        j = 0;
    } else if(col < 6){
        j = 3;
    } else{
        j = 6;
    }

    int sum = 0;
    for(int a = 0; a < 3; a++, i++){
        for(int b = 0; b < 3; b++, j++){
            if(board[i][j] != '.'){
                sum += (board[i][j] - '0');
            }
        }
    }

    return sum >= 45;
}

// checks if the box contains the target
bool boxContains(std::vector<std::vector<char>>& board, int row, int col, int target){
    int i, j;

    if(row < 3){
        i = 0;
    } else if(row < 6){
        i = 3;
    } else{
        i = 6;
    }

    if(col < 3){
        j = 0;
    } else if(col < 6){
        j = 3;
    } else{
        j = 6;
    }

    for(int a = 0; a < 3; a++, i++){
        for(int b = 0; b < 3; b++, j++){
            if(board[i][j] != '.' && (board[i][j] - '0') == target){
                return true;
            }
        }
    }

    return false;
}

// uses back-tracking to solve sudoku puzzle
void solveSudoku(std::vector<std::vector<char>>& board) {     
    int row = 0;
    int col = 0;
    int guess = 1; // from 1 to 9

    while(true){
        if(row == 9){ // end of board reached, stop program
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

        board[row][col] = (char)guess; // make a guess

				// if the guess conflicts with a given number, try again
        if(rowContains(board, row, guess)    ||
           columnContains(board, col, guess) ||
           boxContains(board, row, col, guess)){
            board[row][col] = '.';
            guess++;
            continue;
        }

				// if guess violates sudoku rule, then try again
        if(checkRow(board, row)    ||
           checkColumn(board, col) ||
           checkBox(board, row, col)){
            board[row][col] = '.';
            guess++;
            continue;
        }
        col++;
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

    return 0;
}
