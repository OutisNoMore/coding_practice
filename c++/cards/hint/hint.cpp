#include <iostream>
#include <string>
#include <fstream>

#include "hint.h"


hint::hint(){
  loadTable();
}

void hint::loadTable(){
  std::fstream hint;  
  hint.open("hint/hint.txt");
  char c;

  for(int i = 0; i < 11; i++){
    for(int j = 0; j < 11; j++){
      hint.get(c);
      if(j != 10){ //ignore last character(new line)
        hintTable[i][j] = c;
      }
    }
  }
}

void hint::getHint(int playerHand, int dealerHand){
  printTable();
  makeSuggestion(playerHand, dealerHand);
}

void hint::printTable(){
  std::cout << "^^^^^^^^^^^^Dealer Hand^^^^^^^^^^^^" << std::endl;
  std::cout << "Player 2 3 4 5 6 7 8 9 10 A" << std::endl;
  std::cout << "5-7:   ";
  for(int i = 0; i < 11; i++){
    if(i != 0){
      std::cout << i+7 << ":";
      if(i+7 < 10){
        std::cout << "     ";//formatting for single digit
      }else{
        std::cout << "    ";//formatting for double digit
      }
    }
    for(int j = 0; j < 10; j++){
      std::cout << hintTable[i][j] << " ";
    } 
    std::cout << std::endl;
  }
}

void hint::makeSuggestion(int playerHand, int dealerHand){
  char hint;
  
  if(playerHand <= 7){
    hint = 'H';
  }else if(playerHand >= 17){//last row
    hint = hintTable[10][dealerHand-2];
  }else{
    hint = hintTable[playerHand-7][dealerHand-2];
  }

  std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
  if(hint == 'S'){
    std::cout << "Suggestion: Stand" << std::endl;
  }else{
    std::cout << "Suggestion: Hit" << std::endl;
  }
  std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
}
