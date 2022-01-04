#include <cstdio>

#include "tree.h"

Tree::Tree(int value): _value(value), _childA(nullptr), _childB(nullptr){
}

Tree* Tree::getA() const {
	return _childA;
}

Tree::~Tree(){
  
}

Tree* Tree::getB() const {
	return _childB;
}

bool Tree::addChild(int value){
	if(_childA == nullptr){
		_childA = new Tree(value);
		return true;
	}
	if(_childB == nullptr){
		_childB = new Tree(value);
		return true;
	}

	if(_childB->getB()){
		return _childA->addChild(value);
	}

	if(_childA->getB()){
		return _childB->addChild(value);
	}

	return _childA->addChild(value);
}

bool Tree::search(int value) const{
	if(_value == value){
		return true;
	}
	if(_childA == nullptr && _childB == nullptr){
		return false;
	
	}
	if(_childB == nullptr){
		return _childA->search(value);
	}

	return _childA->search(value) || _childB->search(value);
}
