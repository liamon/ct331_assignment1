#include <stdio.h>

int main(int arg, char* argc[]){
  int integer = 23;
  int* integerPointer = &integer;
  long longInteger = 2452;
  double* doublePointer;
  char** pointerToCharPointer;

  printf("Size of int = %zu\n", sizeof(integer));
  printf("Size of int* = %zu\n", sizeof(integerPointer));
  printf("Size of long = %zu\n", sizeof(longInteger));
  printf("Size of double* = %zu\n", sizeof(doublePointer));
  printf("Size of char** = %zu\n", sizeof(pointerToCharPointer));
  return 0;
}
