#include <iostream>
#include "nodes.h"

int main(){
  std::cout << "---Testing List----" << std::endl;
  LinkedList<LinkedList<City>> test;
  LinkedList<City> test1;
  LinkedList<City> test2;

  test.add(test1);
  test.add(test2);

  test[0].add(c1);
  test[0].add(City("test2", 200));
  test[0].add(City("test3", 300));

  test[1].add(City("test4", 400));
  test[1].add(City("test5", 500));
  test[1].add(City("test6", 600));

  std::cout << "Printing List" << std::endl;
  for(int i = 0; i < test.size(); i++){
    std::cout << test[i].toString() << " ";
    std::cout << std::endl;
  }


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
