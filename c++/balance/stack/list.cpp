#include <cstdio>

#include "list.h"

List::List(): _head(nullptr), _tail(nullptr), _size(0){
}

List::~List(){
	for(Node *np = _head; np != nullptr;){
		Node *temp = np;
		np = np->next;
		delete temp;
	}
}

void List::push(char value){
	_size++;
	Node *np = new Node(value);

	if(_head == nullptr){
		_head = np;
		_tail = np;
		return;
	}

	_tail->next = np; // sets the next of the i-1 element in the list
	_tail = np; // sets tail to the last value in list
}

char List::pop(){
	if(_head == nullptr){
		return 'f';
	}
	_size--;	
	char c = _tail->value;
	//only single element in list
	if(_head == _tail){
		delete _tail;
		_head = _tail = nullptr;
		return c;
	}
	
	for(Node *np = _head; np->next != nullptr; np = np->next){
		if(np->next == _tail){
			delete _tail;
			np->next = nullptr;
			_tail = np;
			return c;
		}
	}

	return 'f';
}

bool List::search(char value){
	if(_head == nullptr){
		return false;
	}

	for(Node *np = _head; np != nullptr; np= np->next){
		if(np->value == value){
			return true;
		}
	}

	return false;
}

bool List::insert(char value1, char value2){
	if(_head == nullptr){
		return false;
	}
	
	for(Node *np = _head; np != nullptr; np = np->next){
		if(np->value == value1){
			Node *n = new Node(value2);
			n->next = np->next;
			np->next = n;
			if(n->next == nullptr){
				_tail = n;
			}
			_size++;
			return true;
		}
	}

	return false;
}

bool List::remove(char value){
	if(_head == nullptr){
		return false;
	}

	//for removing single element
	if(_head->value == value){
			_size--;
		if(_head == _tail){
			delete _head;
			_head = _tail = nullptr;
			return true;
		}else{
			//for removing first element
			Node *temp = _head;
			_head = _head->next;
			delete temp;
			return true;
		}
	}

	//for removing element in middle
	for(Node *np = _head; np->next != nullptr; np = np->next){
		if(np->next->value == value){
			Node *temp = np->next;
			np->next = np->next->next; 
			delete temp;
			if(np->next == nullptr){
				_tail = np;
			}
			_size--;
			return true;
		}
	}

	return false;
}

int List::size(){
	return _size;
}

void List::dump(){
	printf("List values: ");

	for(Node *np = _head; np != nullptr; np = np->next){
		if(np != _head){
			printf("->");
		}
		printf("%c", np->value);
	}

	printf("\n");
}
