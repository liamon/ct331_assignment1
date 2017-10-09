#include <stdio.h>
#include "genericLinkedList.h"
#include "tests.c"

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
  printf("%d\n", *(int*)intToPrint);
}

void printChar(void* charToPrint) {
  printf("%c\n", *(char*)charToPrint);
}

void printFloat(void* floatToPrint) {
  printf("%f\n", *(float*)floatToPrint);
}

void printDouble(void* doubleToPrint) {
  printf("%lf\n", *(double*)doubleToPrint);
}
