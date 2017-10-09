#include <stdio.h>
#include <string.h>
#include "genericLinkedList.h"
#include "tests.h"

void runTests(){
  printf("Tests running...\n\n");

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

// I can't really tests the print versions with a boolean since their return
// type is void, so I have to do it like this instead.
void testGenericness() {
  puts("Testing Genericness.");
  
  char plusSign = '+';
  printf("Expected: %c\n", plusSign);
  genericListElement* element = createEl(&plusSign, sizeof(char), &printChar);
  printf("Actual: ");
  element->print(element->data);

  int integer = 4845;
  printf("Expected: %d\n", integer);
  element = createEl(&integer, sizeof(int), &printInt);
  printf("Actual: ");
  element->print(element->data);

  double floatingPoint = 192.375;
  printf("Expected: %lf\n", floatingPoint);
  element = createEl(&floatingPoint, sizeof(double), &printDouble);
  printf("Actual: ");
  element->print(element->data);

  char* string = "This is a test.";
  printf("Expected: %s\n", string);
  // sizeof(string) will just return the size of the pointer/address, so I have
  // to use strlen. strlen ignores '\0', so I have to + 1 to include it.
  element = createEl(&string, strlen(string) + 1, &printString);
  printf("Actual: ");
  element->print(element->data);
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
