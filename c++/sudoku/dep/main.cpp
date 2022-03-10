#include <iostream>

#include "Board.hpp"

int main(){
  Board game;
  game.printBoard();
  game.solve();
  game.printSolution();
  game.printBoard();
}
