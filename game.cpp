#include <iostream>
#include <string>

#include "player/player.h"
#include "hint/hint.h"

using namespace std;

void menu();

int main(){
  srand(time(NULL));

  menu();

  cout << endl << "Good bye..." << endl;

  return 0;
}

void menu(){
  player user(false);
  player dealer(true);
  hint myHint;
  bool keepGoing = true;
  bool playGame = true;
  int choice;

  do{
    cout << "**********************************" << endl;
    cout << "1) New Hand\n" <<
      	    "2) Hit Me\n"   <<
 	    "3) Stand\n"    <<
	    "4) Hint\n"     <<
	    "5) Exit"       << endl;
    cout << "**********************************" << endl;
    cout << "Your choice?> ";
    cin  >> choice;
    cout << endl;

    switch(choice){
      case 1:
        user.newGame();
	dealer.newGame();
	break;
      case 2:
	user.hitMe();
	if(user.getCount() > 21);
	else break;
      case 3:
	keepGoing = user.finishGame(dealer);
	break;
      case 4:
	myHint.getHint(user.getCount(), dealer.getCount());
	break;
      case 5:
	playGame = user.exit();
	break;
      default:
	cout << "Please make a valid choice" << endl;
	cin.clear();
	cin.ignore();
    }

    cout << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "Dealer Hand: " << dealer.getCount() << endl;
    cout << "Player Hand: " << user.getCount()   << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
  
    char again;
    if(!keepGoing){
      cout << "Play again(Enter Y or N)? ";
      cin >> again;
      if(again == 'Y' || again == 'y'){
        keepGoing = true;
	playGame = true;
        user.setGame(false);
        dealer.setGame(false);	
      }else{
        playGame = false;
      }
    }
  }while(playGame);
}
