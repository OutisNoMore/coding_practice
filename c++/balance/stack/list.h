#ifndef LIST_H_
#define LIST_H_


#include "node.h"

class List{
	private:
		Node* _head;
		Node* _tail;
		int _size;

	public:
		List();
		~List();
		void push(char);
		char pop();
		bool search(char);
		bool insert(char, char);
		bool remove(char);
		int size();
		void dump();
};

#endif //LIST_H_
