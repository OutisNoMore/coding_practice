#include <iostream>

#include "LinkedList/LinkedList.hpp"
#include "ListGraph/ListGraph.hpp"
#include "City.hpp"

int main(){
  try{
    City c1("test1", 100);
    City c2("test2", 200);
    std::cout << "-----Testing Graph----" << std::endl;
    ListGraph<City> GraphTest;
    GraphTest.addNode(c1);
    GraphTest.addNode(c2);
    GraphTest.addEdge(c1, c2, 10.0);
    GraphTest.addEdge(c1, City("test4", 50), 5.0);
    GraphTest.addEdge(c2, City("test3", 100), 2);
    GraphTest.addEdge(c2, City("test5", 60), 9.87);
    std::cout << GraphTest.toString() << std::endl;
    std::cout << "Dijkstras from c1" << std::endl;
    City* path = GraphTest.dijkstra(c1, City("test5", 60));
    for(int i = 0; i < 5; i++){
      std::cout << path[i].toString() << " ";
    }
    delete [] path;
    std::cout << std::endl;
    std::cout << "Removing node test" << std::endl;
    GraphTest.removeNode(c2);
    std::cout << GraphTest.toString() << std::endl;
    std::cout << "Removing edge" << std::endl;
    GraphTest.removeEdge(c1, c2);
    std::cout << GraphTest.toString() << std::endl;
  }
  catch(const char* msg){
    std::cerr << msg << std::endl;
  }

  return 0;
}
