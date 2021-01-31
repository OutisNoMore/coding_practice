#include <cstdio>

#include "tree.h"

int main(){
	Tree t1(1);
	t1.addChild(2);
	t1.addChild(3);
	t1.addChild(4);
	t1.addChild(5);
	for(int i = 6; i < 1000; i++){
		t1.addChild(i);
	}
	if(t1.search(996)){
		printf("yay\n");
	}else{
		printf("boo\n");
	}

	return 0;
}
