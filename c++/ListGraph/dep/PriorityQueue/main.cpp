#include <iostream>

#include "PriorityQueue.hpp"

template <typename T>
class CompareMin{
  public:
    bool operator()(T i1, T i2){
      return i1 < i2;
    }
};

template <typename T>
class CompareMax{
  public:
    bool operator()(T i1, T i2){
      return i1 > i2;
    }
};

int main(){
  PriorityQueue<int, CompareMax<int>> minQueue;
  minQueue.push(10);
  minQueue.pop();
  minQueue.push(11);
  minQueue.push(12);
  std::cout << minQueue.toString() << std::endl;
  minQueue.push(9);
  minQueue.push(8);
  std::cout << minQueue.toString() << std::endl;
  std::cout << minQueue.pop() << std::endl;
  std::cout << minQueue.toString() << std::endl;
  PriorityQueue<int, CompareMin<int>> maxQueue;
  maxQueue.push(10);
  maxQueue.push(11);
  maxQueue.push(12);
  std::cout << maxQueue.toString() << std::endl;
  maxQueue.push(9);
  maxQueue.push(8);
  std::cout << maxQueue.toString() << std::endl;
  std::cout << maxQueue.pop() << std::endl;
  std::cout << maxQueue.toString() << std::endl;
 return 0;
}
