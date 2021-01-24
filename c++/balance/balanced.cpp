#include "balanced.h"

Balanced::Balanced(const char* string){
	int sum = 0;
	//first pass, count only parenthesis
	for(int i = 0; string[i]; i++){
		if(searchOpen(string[i]) || searchClose(string[i])){
			sum++;
		}
	}

	symbols = new char[sum];
	//add only parenthesis
	for(int index = 0, i = 0; string[i]; i++){
		if(searchOpen(string[i]) || searchClose(string[i])){
			symbols[index++] = string[i];
		}
	}
}

Balanced::~Balanced(){
	delete [] symbols;
}

bool Balanced::searchOpen(char find){
	for(int i = 0; i < 4; i++){
		if(find == _opening[i]){
			return true;
		}
	}

	return false;
}

bool Balanced::searchClose(char find){
	for(int i = 0; i < 4; i++){
		if(find == _closing[i]){
			return true;
		}
	}

	return false;
}

char Balanced::opposite(char find){
	for(int i = 0; i < 4; i++){
		if(find == _closing[i]){
			return _opening[i];
		}
	}

	return 'f';
}

bool Balanced::isBalanced(){
	char c;

	if(!symbols[0]){
		return false;
	}
	for(int i = 0; symbols[i]; i++){
		if(searchOpen(symbols[i])){
			stack.push(symbols[i]);
		}else{
			c = stack.pop();
			if(c == 'f'){ //if pop fails/nothing to pop in stack
				return false;
			}
			if(opposite(symbols[i]) != c){ //if pop does not match with current symbol
				return false;
			}
		}
	}

	return stack.size() == 0;  
}
