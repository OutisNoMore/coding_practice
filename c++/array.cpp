#include <iostream>

int main(){
  // can create new pointer/array but can't change value at
  const int* arr1 = new int[5];
  delete [] arr1;
  arr1 = new int[6]; // legal
  // arr1[0] = 1 // illegal
  delete [] arr1;
  
  int* const arr2 = new int[3];
  // legal:
  arr2[0] = 0;
  arr2[1] = 1;
  arr2[2] = 2;
  delete [] arr2;
  // arr2 = new int[3]; // illegal
}
