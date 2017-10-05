#include <stdio.h>
#include "genericLinkedList.h"

void runTests(){
  printf("Tests running...\n");

  //...

  printf("\nTests complete.\n");
}

void printTestResults(testFunction test, char* testDescription) {
  if (test()) {
    printf("%s: SUCCESS\n", testDescription);
  } else {
    printf("%s: FAILURE\n", testDescription);
  }
}

void printInt(void* intToPrint) {
  printf("%d\n", intToPrint);
}

void printChar(void* charToPrint) {
  printf("%c\n", charToPrint);
}

void printFloat(void* floatToPrint) {
  printf("%f\n", floatToPrint);
}

void printDouble(void* doubleToPrint) {
  printf("%lf\n", doubleToPrint);
}
