#ifndef PLAYER_H
#define PLAYER_H

class player{
private:
  bool isDealer = false;
  bool inGame = false;
  int count = 0;
public:
  player(bool isDealer);
  void newGame();
  void hitMe();
  void setGame(bool inGame);
  int getCount();
  bool finishGame(player& dealer);
  bool exit();
};

#endif
