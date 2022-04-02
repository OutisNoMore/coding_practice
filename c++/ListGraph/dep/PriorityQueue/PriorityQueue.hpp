#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <string>
#include "nodes.hpp"

template <typename E, typename C>
class PriorityQueue{
  private:
    node<E>* _head;
    C comparator; 
    int _size;

  public:
    PriorityQueue();
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

template <typename E, typename C>
PriorityQueue<E, C>::PriorityQueue(){
  _head = nullptr;
  _size = 0;
}

template <typename E, typename C>
PriorityQueue<E, C>::PriorityQueue(E root){
  _head = new node<E>(root);
  _size = 1;
}

template <typename E, typename C>
PriorityQueue<E, C>::~PriorityQueue(){
  if(_size != 0){
    for(node<E>* curr = _head->next; curr != nullptr;){
      delete curr->last;
      curr = curr->next;
    }
  }
  _size = 0;
}

template <typename E, typename C>
void PriorityQueue<E, C>::bubbleDown(){
  for(node<E>* current = _head; current->next; current = current->next){
    if(comparator(current->element, current->next->element)){
      E temp = current->element;
      current->element = current->next->element;
      current->next->element = temp;
    }
  }
}

template <typename E, typename C>
void PriorityQueue<E, C>::push(E element){
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

template <typename E, typename C>
E PriorityQueue<E, C>::pop(){
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

template <typename E, typename C>
E PriorityQueue<E, C>::peek(){
  if(_size == 0){
    throw "Empty Queue";
  }
  return _head->element;
}

template <typename E, typename C>
std::string PriorityQueue<E, C>::toString(){
  std::string output = "";
  for(node<E>* current = _head; current != nullptr; current = current->next){
    output = output + std::to_string(current->element) + ", ";
  }
  return output;
}

#endif // PRIORITYQUEUE_H
