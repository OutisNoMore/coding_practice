package main

import "fmt"

func fibo(term int) int {
	if(term == 0){
		return 0;
	}
	if(term == 1){
		return 1;
	}
	var a = 0;
	var b = 1;

	for n := 2; n <= term; n++ {
		b = a + b;
		a = b - a;
	}

	return b;
}

func recurFibo(term int) int {
	if(term <= 1){
		return term;
	}

	return recurFibo(term-1) + recurFibo(term-2);
}

func main(){
	for i := 0; i < 10; i++ {
		fmt.Print(fibo(i), " ");
	}
	fmt.Println();

	for j := 0; j < 10; j++ {
		fmt.Print(recurFibo(j), " ");
	}
	fmt.Println();
}
