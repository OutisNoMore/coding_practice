#include <iostream>
#include <chrono>

int binSearch(int* array, int target, int size);

int main(){
	int* arr = new int[100];

	for(int i = 0; i < 10; i++){
		arr[i] = i;
	}


	std::cout << binSearch(arr, 1, 10)  << std::endl;
	std::cout << binSearch(arr, 5, 10)  << std::endl;
	std::cout << binSearch(arr, 10, 10) << std::endl;
	std::cout << binSearch(arr, 7, 10)  << std::endl;
	std::cout << binSearch(arr, 3, 10)   << std::endl;

	delete [] arr;

	return 0;
}

int binSearch(int* array, int target, int size){
	int left  = 0;
	int right = size - 1;
	int mid   = (left + right) / 2;

	while(array[mid] != target){
		if(mid > right || mid < left){
			return -1;
		}

		if(array[mid] < target){
			left = mid + 1;
		} 
		else{
			right = mid - 1;
		}

	  mid = (left + right) / 2;
	}

	return mid;
}
