#ifndef HINT_H
#define HINT_H

class hint{
private:
  char hintTable[11][10];
public:
  hint();
  void loadTable();
  void getHint(int playerHand, int dealerHand);
  void printTable();
  void makeSuggestion(int playerHand, int dealerHand);
};

#endif
