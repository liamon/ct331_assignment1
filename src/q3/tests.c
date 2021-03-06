#include <stdio.h>
#include <string.h>
#include "genericLinkedList.h"
#include "tests.h"

void runTests(){
  printf("Tests running...\n\n");

  printTestResults(&testEnqueueAndPush, "enqueue() and push()");
  printTestResults(&testPopFromEmptyList, "Popping from an empty list");
  printTestResults(&testPopFromLongerList, "Popping from a longer list");
  printTestResults(&testDequeueFromEmptyList, "Dequeueing from an empty list)");
  printTestResults(&testDequeueFromLongerList, "Dequeueing from a longer list");
  
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

int testEnqueueAndPush() { // enqueue() just calls push(), so this tests both.
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

int testPopFromEmptyList() {
  genericListElement* empty = NULL;
  genericListElement* popped = pop(&empty);
  return empty == NULL && popped == NULL;
}

int testPopFromLongerList() {
  char colon = ':';
  genericListElement* testList = createEl(&colon, sizeof(char), &printChar);
  genericListElement* popped = pop(&testList);
  return *((char*) popped->data) == colon && popped->next == NULL &&
    testList == NULL;
}

int testDequeueFromEmptyList() {
  genericListElement* empty = NULL;
  genericListElement* testReturn = dequeue(empty);
  return empty == NULL && testReturn == NULL;
}

int testDequeueFromLongerList() {
  // Note that I have designed this test to avoid triggering the bug that
  // occurs when someone tries to dequeue a list of length 1...
  int testInt = 31;
  char testChar = '\\'; // Backslash has to be escaped with another backslash.
  genericListElement* list = createEl(&testInt, sizeof(int), &printInt);
  enqueue(&list, &testChar, sizeof(char), &printChar);
  genericListElement* dequeued = dequeue(list);
  
  return *((char*) list->data) == testChar && list->next == NULL &&
    *((int*) dequeued->data) == testInt && dequeued->next == NULL;
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
