#include <iostream>
#include "nodes.h"

int main(){
  node<int>* i = new node<int>(5);
  i->next = new node<int>(6);
  std::cout << sizeof(i) << std::endl;
  std::cout << sizeof(*i) << std::endl;
  std::cout << i << std::endl;
  std::cout << i->next << std::endl;
  std::cout << i->element << std::endl;
  std::cout << (i + 0x20) << std::endl;
/*  node<double> d(5.0);
  std::cout << sizeof(d) << std::endl;
  std::cout << sizeof(*d) << std::endl;
  */

  delete i->next;
  delete i;
  return 0;
}
