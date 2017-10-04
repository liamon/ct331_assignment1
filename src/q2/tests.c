#include <stdio.h>
#include <string.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  traverse(l);
  printf("\n");

  printf("Liam's new tests running...\n\n");
  
  printTestResults(testPushToEmptyList(), "Pushing to an empty list");
  printTestResults(testEnqueueToEmptyList(), "Enqueueing to an empty list");
  printTestResults(testPushToExistingList(), "Pushing to an existing list");
  printTestResults(testEnqueueToExistingList(), "Enqueueing to an existing list");
  
  printf("\nTests complete.\n");
}

void printTestResults(int isTestSuccess, char* testDescription) {
  if (isTestSuccess) {
    printf("%s: SUCCESS\n", testDescription);
  } else {
    printf("%s: FAILURE\n", testDescription);
  }
}

int testPushToEmptyList() {
  listElement* testList = NULL;
  char* testData = "Test push";
  push(&testList, testData, sizeof(testData));
  return strcmp(testData, testList->data) == 0 && testList->next == NULL;
}

int testEnqueueToEmptyList() {
  listElement* testList = NULL;
  char* testData = "Test enqueue";
  enqueue(&testList, testData, sizeof(testData));
  return strcmp(testData, testList->data) == 0 && testList->next == NULL;
}

int testPushToExistingList() {
  listElement* testList = createEl("Test", sizeof("Test"));
  char* testData = "Test push";
  push(&testList, testData, sizeof(testData));
  return strcmp(testData, testList->data) == 0 && testList->next != NULL &&
    strcmp("Test", testList->next->data) == 0 && testList->next->next == NULL;
}

int testEnqueueToExistingList() {
  listElement* testList = createEl("Test", sizeof("Test"));
  char* testData = "Test enqueue";
  enqueue(&testList, testData, sizeof(testData));
  return strcmp(testData, testList->data) == 0 && testList->next != NULL &&
    strcmp("Test", testList->next->data) == 0 && testList->next->next == NULL;
}
