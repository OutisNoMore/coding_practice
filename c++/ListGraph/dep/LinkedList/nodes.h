#ifndef NODES_H
#define NODES_H

template <typename E>
struct node{
  node* next;
  node* last;
  E element;

  node(E element){
    this->element = element;
    next = nullptr;
    last = nullptr;
  }
};

#endif // NODES_H
