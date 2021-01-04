#include <iostream>
#include <string> 
#include <exception>

#include "player.h"

player::player(bool isDealer){
  this->isDealer = isDealer;
}

void player::newGame(){
  if(inGame){
    std::cout << "Please finish game before starting a new one" << std::endl;
    return;
  }else{
    inGame = true;
    hitMe();
  }
}

void player::hitMe(){
  if(!inGame){
    std::cout << "Please start a game first" << std::endl;
    return;
  }

  int suit = rand()%4;
  int face = rand()%13+1;
  std::string sFace = "";
  std::string sSuit = "";

  switch(suit){
    case 0:
      sSuit = "spades";
      break;
    case 1:
      sSuit = "clubs";
      break;
    case 2:
      sSuit = "hearts";
      break;
    case 3:
      sSuit = "diamonds";
  }

  if(face == 1 && (count+11) > 21){
    sFace = "ace";
    count += 1;
  }else if(face == 1){
    sFace = "ace";
    count += 11;
  }else if(face == 11){
    sFace = "jack";

    count += 10;
  }else if(face == 12){
    sFace = "queen";
    count += 10;
  }else if(face == 13){
    sFace = "king";
    count += 10;
  }else{
    sFace = std::to_string(face);
    count += face;
  }

  std::string name = "You";
  if(isDealer){
    name = "Dealer";
  }
  std::cout << name << " drew a " << sFace << " of " << sSuit << std::endl;
}

int player::getCount(){
  return count;
}

void player::setGame(bool inGame){
  this->inGame = inGame;
  count = 0;
}

//returns if player should stay in game
bool player::finishGame(player& dealer){
  if(!inGame){
    std::cout << "Please start a game first" << std::endl;
    return true;
  }

  while(dealer.getCount() < 17){
    dealer.hitMe();
  } 
  std::cout << std::endl;

  if(dealer.getCount() > 21 && count > 21){
    std::cout << "Both player and house bust, draw" << std::endl;
  }else if(dealer.getCount() > 21){
    std::cout << "Dealer bust, player wins!" << std::endl;
  }else if(count > 21){
    std::cout << "Player busts, house wins" << std::endl;
  }else if(dealer.getCount() == count){
    std::cout << "House and player have the same hand, Draw" << std::endl;
  }else if(count > dealer.getCount()){
    std::cout << "Player has higher hand, player wins!" << std::endl;
  }else{
    std::cout << "Dealer has higher card, house wins" << std::endl;
  }

  return false;
}

//returns if player should stay in game
bool player::exit(){
  if(inGame){
    std::cout << "Please finish game first" << std::endl;
    return true;
  }else{
    return false;
  }
}

