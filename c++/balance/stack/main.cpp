#include <cstdio>

#include "list.h"

int main(){
	List test;
	printf("%c\n", test.pop());
	test.push('h');
	test.push('e');
	test.dump();
	printf("%d\n", test.size());

	printf("%c\n", test.pop());
	test.dump();
	printf("%d\n", test.size());

	return 0;
}
