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

  printTestResults(&testLengthEmpty, "Checking length of empty lists");
  printTestResults(&testLength, "Checking length of non-empty lists");
  
  printTestResults(&testPushToEmptyList, "Pushing to an empty list");
  printTestResults(&testEnqueueToEmptyList, "Enqueueing to an empty list");
  printTestResults(&testPushToExistingList, "Pushing to an existing list");
  printTestResults(&testEnqueueToExistingList, "Enqueueing to an existing list");
  
  printTestResults(&testDequeueFromEmptyList, "Dequeueing from an empty list");
  printTestResults(&testDequeueWhichEmptiesList, "Dequeueing and emptying a list");
  printTestResults(&testDequeue, "Dequeueing from a list of length >= 2");

  printTestResults(&testPopFromEmptyList, "Popping from an empty list");
  printTestResults(&testPopWhichEmptiesList, "Popping and emptying a list");
  printTestResults(&testPop, "Popping from a list of length >= 2");

  
  printf("\nTests complete.\n");
}

void printTestResults(testFunction test, char* testDescription) {
  if (test()) {
    printf("%s: SUCCESS\n", testDescription);
  } else {
    printf("%s: FAILURE\n", testDescription);
  }
}

int testLengthEmpty() {
  listElement* empty = NULL;
  return length(empty) == 0;
}

int testLength() {
  listElement* list = createEl("thing", sizeof("thing"));
  int length1 = length(list);
  push(&list, "new", sizeof("new"));
  int length2 = length(list);
  return length1 == 1 && length2 == 2;
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

int testDequeueFromEmptyList() {
  listElement* testList = NULL;
  listElement* testReturn = dequeue(testList);
  return testList == NULL && testReturn == NULL;
}

int testDequeueWhichEmptiesList() {
  char* testData = "Only one element.";
  listElement* testList = createEl(testData, sizeof(testList));
  listElement* testReturn = dequeue(testList);
  return strcmp(testReturn->data, testData) == 0 && testReturn->next == NULL &&
    testList == NULL;
}

int testDequeue() {
  char* data1 = "First";
  char* data2 = "Second";
  listElement* testList = createEl(data1, sizeof(data1));
  enqueue(&testList, data2, sizeof(data2));

  listElement* testReturn = dequeue(testList);
  return strcmp(testList->data, data2) == 0 && testList->next == NULL &&
    strcmp(testReturn->data, data1) == 0 && testReturn->next == NULL;
}

int testPopFromEmptyList() {
  listElement* empty = NULL;
  listElement* testReturn = pop(&empty);
  return empty == NULL && testReturn == NULL;
}

int testPopWhichEmptiesList() {
  char* testData = "Only one element.";
  listElement* testList = createEl(testData, sizeof(testData));
  listElement* testReturn = pop(&testList);
  return strcmp(testReturn->data, testData) == 0 && testReturn->next == NULL &&
    testList == NULL;
}

int testPop() {
  char* data1 = "First";
  char* data2 = "Second";
  listElement* testList = createEl(data1, sizeof(data1));
  enqueue(&testList, data2, sizeof(data2));

  listElement* testReturn = pop(&testList);
  return strcmp(testList->data, data1) == 0 && testList->next == NULL &&
    strcmp(testReturn->data, data2) == 0 && testReturn->next == testList;
}
