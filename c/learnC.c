#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * All same primitives as c++, except bool
 * Create bool using define directive
 */

#define BOOL char // Define BOOL as a char/string
#define FALSE 0   // Define FALSE as 0
#define TRUE 1    // Define TRUE as 1

int sum(int num){
  static int output = 0; // only declared once, even if called multiple times
  output += num;
  return output;
}

struct data{
  int x;
  int y;
};

typedef struct{
  int x;
  int y;
} test;

void moveX(test* coordinate){
  coordinate->x++;
}

typedef struct{
  char* name;
  int age;
} person;

union uTest{
  int i;
  int i2;
  float d;
  char c[20];
};

typedef union{
  int theInt;
  char bytes[sizeof(int)];
} intParts;

int main(){
  const char* msg = "Hello, World";
  puts(msg); // prints as string literal
  printf("%s\n", msg); // interprets formatting

  int a = 0;
  printf("My int: %d\n", a);
  float b = 1.123456;
  printf("My float: %.2f\n", b);

  a = b; // automatically truncates, no error
  printf("a is %d\n", a);
  b = a; // converts to float no error
  printf("b is %f\n", b);
  double c = b;
  printf("c is %f\n", c);

  BOOL d = FALSE;
  BOOL e = TRUE;
  printf("%d\n%d\n", d, e);
  // Prints False
  if(d){
    puts("True");
  }
  else{
    puts("False");
  }
  // Prints true
  if(e){
    puts("True");
  }
  else{
    puts("False");
  } 

  /*
   * ARRAY!
   */
  int numbers[10];
  printf("%d\n", numbers[0]); // prints random value/whatever is at mem address
  for(int i = 0; i < 10; i++){
    numbers[i] = i+1;
  }
  printf("%d\n", numbers[0]); // prints 1

  int matrix[5][2];
  matrix[0][0] = 1;
  matrix[1][1] = 2;
  int mat[2][2] = {
    {0, 1},
    {2, 3}
  };
  printf("%d\n", mat[0][0]); // prints 0
  // Can also initialize: int mat[x][y] = {n_1, n_2, n_3, n_4, ...};

  const char* str1 = "Help!\0";   // null terminate!, pointer to const char
                                  // Cannot change elements of str1, but can change pointer
  printf("%s\n", str1);
  str1 = "nope!\0";
  printf("str1: %s\n", str1);
  // str1[0] = 'a'; // illegal
  const char str2[6] = "Help!\0";  // array of const char, Cannot change pointer, but can change element
  // str2 = "nope!\0"; // illegal
  // str2[n] = 'a'; // illegal
  // const char[n] var = "string"; // will not work, cannot initialize array of const char
  // char test[]; // illegal need to initialize at declaration
  printf("str2: %s\n", str2);
  printf("strlen(str2): %lu\n", strlen(str2)); // length of string
  int compare = strncmp(str1, str2, 6);
  if(compare == 0){
    puts("Are the same!");
  }
  else if(compare < 0){
    puts("str1 is either shorter, or alphabetically lower than str2");
  }
  else{
    puts("str2 is either shorter or alphabetically lower than str1");
  }

  char combine[12] = {'\0'}; // null initialize string
  strncat(combine, str1, 5);
  strncat(combine, str2, 6);
  // "nope!Help!\0";
  printf("combine: %s\n", combine);
  sprintf(combine, "%s %s", str1, str2); // initializes combine to the formatted string
  printf("combine: %s\n", combine);
  sum(10);
  sum(20);
  sum(30);
  printf("%d\n", sum(40)); // prints 100

  int* ptrA = &a; // points to mem address of int a
  (*ptrA)++; // update value of a by 1
  printf("%d\n", a);

  struct data mine;
  mine.x = 10;
  mine.y = 20;
  printf("%d %d\n", mine.x, mine.y);

  test tester;
  tester.x = 90;
  tester.y = 80;
  printf("%d %d\n", tester.x, tester.y);
  moveX(&tester);
  printf("%d %d\n", tester.x, tester.y);

  // Dynamic allocation 
  person* p1 = (person*) malloc(sizeof(person)); // malloc allocates memory, and returns pointer to memory chunk
                                                 // return type is void*, which just means pointer to some memory
                                                 // typecast to person pointer 
  free(p1); // must free dynamically allocated memory!

  int** m;
  m = (int**) malloc(3 * sizeof(int*)); // 3 rows
  for(int i = 0; i < 3; i++){
    m[i] = (int*) malloc(3 * sizeof(int)); // 3 columns
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      m[i][j] = i + 10;
    }
  }
  for(int i = 0; i < 3;i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
  // m is now a 3x3 dynamically allocated matrix
  for(int i = 0; i < 3; i++){
    free(m[i]); // free each row
  }
  free(m); // free the overall/top-level pointer

  // Unions!
  // Can only use one member of union at a time - rest are either 0 or null
  //   members with the same data type all share the same value
  // All members share the same memory address
  union uTest u;
  u.i = 256;
  // all members of u are now treated as an int with value 18
  printf("%d %d %f %s\n", u.i, u.i2, u.d, u.c);

  intParts parts;
  parts.theInt = 5968145;
  printf("%d %d %d %d %d\n", parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

  int arr[5] = {1, 2, 3, 4, 5};
  printf("%p %p\n", arr, (arr + 1)); // increments by 4 bytes
  char* arr2 = "Help\0";
  printf("%p %p\n", arr2, (arr2 + 1)); // increments by 1 byte

  // void pointers can act as template type

  return 0;
}
