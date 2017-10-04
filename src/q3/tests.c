#include <stdio.h>
#include "genericLinkedList.h"

void runTests(){
  printf("Tests running...\n");

  //...

  printf("\nTests complete.\n");
}

void printTestResults(int isTestSuccess, char* testDescription) {
  if (isTestSuccess) {
    printf("%s: SUCCESS\n", testDescription);
  } else {
    printf("%s: FAILURE\n", testDescription);
  }
}
