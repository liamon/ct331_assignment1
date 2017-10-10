#include <stdio.h>
#include <string.h>
#include "genericLinkedList.h"
#include "tests.h"

void runTests(){
  printf("Tests running...\n\n");

  printTestResults(&testEnqueueAndPush, "enqueue() and push()");
  testGenericness();

  printf("\nTests complete.\n");
}

void printTestResults(testFunction test, char* testDescription) {
  if (test()) {
    printf("%s: SUCCESS\n", testDescription);
  } else {
    printf("%s: FAILURE\n", testDescription);
  }
}

int testEnqueueAndPush() { // enqueue() just calls push().
  genericListElement* list = NULL;
  int testInt = 3891;
  enqueue(&list, &testInt, sizeof(int), &printInt);
  double testDouble = -47.9375;
  enqueue(&list, &testDouble, sizeof(double), &printDouble);
  
  // I was unable to get comparisons of function pointers to work properly, as
  // dereferenced function pointers are automatically converted to pointers.
  // See https://stackoverflow.com/a/2795596
  return *((double*) list->data) == testDouble &&
    *((int*) list->next->data) == testInt && list->next->next == NULL;
}

// I can't really tests the print versions with a boolean since their return
// type is void, so I have to do it like this instead.
void testGenericness() {
  puts("\nTesting Genericness:");
  
  char plusSign = '+';
  printf("Expected: %c\n", plusSign);
  genericListElement* list = createEl(&plusSign, sizeof(char), &printChar);
  printf("Actual: ");
  list->print(list->data);

  int integer = 4845;
  printf("Expected: %d\n", integer);
  push(&list, &integer, sizeof(int), &printInt);
  printf("Actual: ");
  list->print(list->data);

  double floatingPoint = 192.375;
  printf("Expected: %lf\n", floatingPoint);
  push(&list, &floatingPoint, sizeof(double), &printDouble);
  printf("Actual: ");
  list->print(list->data);

  // sizeof(string) will just return the size of the pointer/address, so I have
  // to use strlen in the test below. strlen ignores '\0', so I have to + 1 to
  // make sure it is put back in again.
  char* string = "This is a test.";
  printf("Expected: %s\n", string);
  push(&list, &string, (strlen(string) + 1) * sizeof(char), &printString);
  printf("Actual: ");
  list->print(list->data);
}

void printInt(void* intToPrint) {
  printf("%d\n", *(int*)intToPrint);
}

void printChar(void* charToPrint) {
  printf("%c\n", *(char*)charToPrint);
}

void printDouble(void* doubleToPrint) {
  printf("%lf\n", *(double*)doubleToPrint);
}

void printString(void* stringToPrint) {
  printf("%s\n", *(char**)stringToPrint);
}
