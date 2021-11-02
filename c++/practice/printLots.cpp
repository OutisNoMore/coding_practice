#include <iostream>
#include <list>

void printLots(std::list<int> L, std::list<int> P);

int main(){
	int LArr[] = {1, 2, 3, 4, 5, 6};
	int PArr[] = {0, 3, 4};

	std::list<int> L(LArr, LArr + sizeof(LArr)/sizeof(int));
	std::list<int> P(PArr, PArr + sizeof(PArr)/sizeof(int));

	printLots(L, P); // Should print 1 4 5
}

void printLots(std::list<int> L, std::list<int> P){
	int LIndex = 0;

	for(std::list<int>::iterator LIt = L.begin(), PIt = P.begin(); LIt != L.end() && PIt != P.end(); LIt++, LIndex++){
		if(*PIt == LIndex){
			std::cout << *LIt << std::endl;
			PIt++;
		}
	}
}
