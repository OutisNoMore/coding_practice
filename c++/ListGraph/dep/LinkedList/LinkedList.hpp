#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "nodes.hpp"

template <typename E>
class LinkedList{
  private:
    node<E>* _head;
    node<E>* _tail;
    int _size;

  public:
    LinkedList();
    LinkedList(E root);
    ~LinkedList();

    void add(E element);
    void append(E element);
    bool remove(int index);

    node<E>* find(E element);
    E& get(int index);
    E& operator[](int index);
    int indexOf(E element);
    int size(){ return _size; }
    std::string toString();
};

template <typename E>
LinkedList<E>::LinkedList(){
  _head = _tail = nullptr;
  _size = 0;
}

template <typename E>
LinkedList<E>::LinkedList(E root){
  _head = new node<E>(root);
  _tail = _head;
  _size = 1;
}

template <typename E>
LinkedList<E>::~LinkedList(){
  for(node<E>* curr = _head; curr != nullptr;){
    if(curr == _tail){
      delete _tail;
      curr = nullptr;
    }
    else{
      curr = curr->next;
      delete curr->last;
    }
  }
  _size = 0;
}

template <typename E>
void LinkedList<E>::add(E element){
  if(_size == 0){
    _head = new node<E>(element);
    _tail = _head;
  }
  else{
    _tail->next = new node<E>(element);
    _tail->next->last = _tail;
    _tail = _tail->next;
  }

  _size++;
}

template <typename E>
void LinkedList<E>::append(E element){
  if(_size == 0){
    _head = new node<E>(element);
    _tail = _head;
  }
  else{
    _head->last = new node<E>(element);
    _head->last->next = _head;
    _head = _head->last;
  }
  _size++;
}

template <typename E>
bool LinkedList<E>::remove(int index){
  if(index > _size || index < 0){
    return false;
  }

  if(index == 0){
    if(_size == 1){
      delete _head;
      _head = _tail = nullptr;
      _size = 0;

      return true;
    }
    else{
      _head = _head->next;
      delete _head->last;
      _head->last = nullptr;
      _size--;

      return true;
    }
  }

  if(index == _size-1){
    _tail = _tail->last;
    delete _tail->next;
    _tail->next = nullptr;
    _size--;

    return true;
  }

  int i = 0;
  for(node<E>* curr = _head; curr != _tail && i < _size; curr = curr->next, i++){
    if(i == index){
      curr->last->next = curr->next;
      curr->next->last = curr->last;
      delete curr;
      _size--;

      return true;
    }
  }

  return false;
}

template <typename E>
node<E>* LinkedList<E>::find(E element){
  for(node<E>* curr = _head; curr != nullptr; curr = curr->next){
    if(curr->element == element){
      return curr;
    }
  }

  return nullptr;
}

template <typename E>
int LinkedList<E>::indexOf(E element){
  int i = 0;
  for(node<E>* curr = _head; curr != nullptr; curr = curr->next, i++){
    if(curr->element == element){
      return i;
    }
  }

  return -1;
}

template <typename E>
E& LinkedList<E>::get(int index){
  if(index >= _size || index < 0){
    throw "Index out of bounds";
  }
  int i = 0;
  for(node<E>* curr = _head; curr != nullptr && i < _size; curr = curr->next, i++){
    if(i == index){
      return curr->element;
    }
  }
  throw "Element does not exist";
}

template <typename E>
E& LinkedList<E>::operator[](int index){
  return this->get(index);
}

template <typename E>
std::string LinkedList<E>::toString(){
  std::string output = "";
  for(node<E>* curr = _head; curr != nullptr; curr = curr->next){
    output += curr->element.toString() + ", ";
  }
  return output;
}

#endif // LINKEDLIST_H
