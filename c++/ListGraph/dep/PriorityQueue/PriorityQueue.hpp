#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <string>
#include "nodes.hpp"

template <typename E>
class PriorityQueue{
  private:
    node<E>* _head;
    bool (*_comparator)(E, E);
    int _size;

  public:
    PriorityQueue();
    PriorityQueue(bool (*comparator)(E, E));
    PriorityQueue(E root);
    ~PriorityQueue();

    void push(E element);
    E pop();
    E peek();
    void bubbleDown();

    bool contains(E element);
    int size(){ return _size; }
    std::string toString();
};

template <typename E>
PriorityQueue<E>::PriorityQueue(){
  _head = nullptr;
  _size = 0;
}

template <typename E>
PriorityQueue<E>::PriorityQueue(bool (*comparator)(E, E)){
  _head = nullptr;
  _size = 0;
  this->_comparator = comparator;
}

template <typename E>
PriorityQueue<E>::PriorityQueue(E root){
  _head = new node<E>(root);
  _size = 1;
}

template <typename E>
PriorityQueue<E>::~PriorityQueue(){
  if(_size != 0){
    for(node<E>* curr = _head->next; curr != nullptr;){
      delete curr->last;
      curr = curr->next;
    }
  }
  _size = 0;
}

template <typename E>
void PriorityQueue<E>::bubbleDown(){
  for(node<E>* current = _head; current->next; current = current->next){
    if(_comparator(current->element, current->next->element)){
      E temp = current->element;
      current->element = current->next->element;
      current->next->element = temp;
    }
  }
}

template <typename E>
void PriorityQueue<E>::push(E element){
  if(_size == 0){
    _head = new node<E>(element);
  }
  else{
    _head->last = new node<E>(element);
    _head->last->next = _head;
    _head = _head->last;
    bubbleDown();
  }
  _size++;
}

template <typename E>
E PriorityQueue<E>::pop(){
  if(_size == 0){
    throw "Empty Queue";
  }
  _size--;
  if(_size == 0){
    E output = _head->element;
    delete _head;
    return output;
  }
  _head = _head->next;
  E output = _head->last->element;
  delete _head->last;
  return output;
}

template <typename E>
E PriorityQueue<E>::peek(){
  if(_size == 0){
    throw "Empty Queue";
  }
  return _head->element;
}

template <typename E>
std::string PriorityQueue<E>::toString(){
  std::string output = "";
  for(node<E>* current = _head; current != nullptr; current = current->next){
    output = output + std::to_string(current->element) + ", ";
  }
  return output;
}

#endif // PRIORITYQUEUE_H
