#ifndef BALANCED_H_
#define BALANCED_H_

#include "stack/list.h"

class Balanced{
	private:
		const char _opening[5] = {'(', '{', '[', '<', '\0'};
		const char _closing[5] = {')', '}', ']', '>', '\0'};
		char* symbols;
		List stack;

	public:
		Balanced(const char*);
		~Balanced();
		bool searchOpen(char);
		bool searchClose(char);
		char opposite(char);
		bool isBalanced();
};

#endif //BALANCED_H_
