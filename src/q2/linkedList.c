#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

// Returns the number of elements in a linked list.
int length(listElement* list) {
  int lengthCounter = 0;
  while (*list != NULL) {
    lengthCounter++;
    list = list->next;
  }
  return lengthCounter;
}

// Push a new element onto the head of a list.
// Update the list reference using side effects.
void push(listElement** list, char* data, size_t size) {
  listElement* newElement = malloc(sizeof(listElement));
  newElement->data = malloc(sizeof(char) * size);
  strcpy(newElement->data, data);
  // By dereferencing list once, it is now a pointer to an
  // address which points to a listElement.
  newElement->next = malloc(sizeof(listElement));
  newElement->next = *list;
  // By dereferencing it twice, it is now a pointer to a listElement.
  listElement** list = newElement; // Side effects.
}

// Enqueue a new element onto the head of a list.
// Update the list reference using side effects.
void enqueue(listElement** list, char* data, size_t size) {
  // This has the same effect as push, so...
  push(list, data, size);
}

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}
