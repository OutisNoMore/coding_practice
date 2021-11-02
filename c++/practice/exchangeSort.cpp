#include <iostream>

const int SIZE =  10;

void exchangeSort(int arr[], int size);
void swap(int* i1, int* i2);
void printArr(int arr[], int size);

int main(){
	int* arr = new int[SIZE];

	for(int i = 10, j = 0; i > 0 && j < 10; i--, j++){
		arr[j] = i;
	}
	exchangeSort(arr, SIZE);
	printArr(arr, SIZE);

	delete [] arr;

	return 0;
}

void swap(int* i1, int* i2){
	int temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}

void exchangeSort(int arr[], int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(arr[j] > arr[i]){
				swap(&arr[j], &arr[i]);
			}
		}
	}
}

void printArr(int arr[], int size){
	for(int i = 0; i < size; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
