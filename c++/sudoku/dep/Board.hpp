#ifndef BOARD_H
#define BOARD_H

enum Level {EASY, MEDIUM, HARD};

class Board{
  private:
    int board[9][9];
    int solution[9][9];
    bool foundSolution = false;
    Level difficulty = EASY;
    // Helper functions
    bool rowContains(int board[9][9], int row, int target);
    bool columnContains(int board[9][9], int col, int target);
    bool boxContains(int board[9][9], int row, int col, int target);
    bool validPosition(int board[9][9], int row, int col, int guess);
    int findSolution(int board[9][9], int row, int col, int count = 0);
    void print(int board[9][9]);
  public:
    /***************
     * CONSTRUCTOR *
     ***************/
    Board();
    /***********
     * MUTATOR *
     ***********/
    void solve();
    void generateGame();
    void printBoard();
    void printSolution();
};

#endif
