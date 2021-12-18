#include <iostream>

#include "LinkedList/LinkedList.h"
#include "ListGraph/ListGraph.h"
#include "City.h"

int main(){
  City c1("test", 100);
  City c2("test2", 200);
  LinkedList<LinkedList<City>> test;
  LinkedList<City> test1;
  LinkedList<City> test2;

  test.add(test1);
  test.add(test2);

  test.get(0).add(c1);
  test.get(0).add(City("test2", 200));
  test.get(0).add(City("test3", 300));

  test.get(1).add(City("test4", 400));
  test.get(1).add(City("test5", 500));
  test.get(1).add(City("test6", 600));

  for(int i = 0; i < test.size(); i++){
    for(int j = 0; j < test.get(i).size(); j++){
      std::cout << (test.get(i).get(j)).toString() << " ";
    }
    std::cout << std::endl;
  }

  ListGraph<City> Gtest;
  Gtest.addNode(c1);
  Gtest.addNode(c2);
  Gtest.addEdge(c1, c2, 10.0);
  std::cout << Gtest.toString() << std::endl;
  Gtest.removeNode(c1);
  std::cout << Gtest.toString() << std::endl;

  return 0;
}
