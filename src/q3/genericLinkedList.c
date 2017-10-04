#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct{
  void* data;
  printData print;
  size_t size;
  struct listElementStruct* next;
} listElement;

// Returns the number of elements in a linked list.
int length(listElement* list) {
  int lengthCounter = 0;
  listElement* current = list; // This avoids side effects changing list.
  while (current != NULL) {
    lengthCounter++;
    current = current->next;
  }
  return lengthCounter;
}

// Push a new element onto the head of a list.
// Update the list reference using side effects.
void push(listElement** list, void* data, size_t size) {
  listElement* newElement = createEl(data, size);
  // By dereferencing list once, it is now a pointer to a listElement.
  newElement->next = *list;
  *list = newElement; // Side effects.
}

// Pop an element from the head of a list.
// Update the list reference using side effects.
listElement* pop(listElement** list) {
  // The bulk of this method requires there to be at least one element, so
  // I have to deal with the special case by returning the empty list.
  if (length(*list) == 0) {
    return *list;
  }

  listElement* head = *list;
  // Create a new element with the same values as the first element.
  listElement* poppedElement = createEl(head->data, sizeof(*(head->data)));
  *list = head->next;

  free(head->data);
  free(head);
  return poppedElement;
}

// Enqueue a new element onto the head of a list.
// Update the list reference using side effects.
void enqueue(listElement** list, void* data, size_t size) {
  // This has the same effect as push, so...
  push(list, data, size);
}

// Dequeue an element from the tail of the list.
listElement* dequeue(listElement* list) {
  
  // This accounts for if there is no second-last element.
  if (length(list) == 0) {
    return NULL;
  }
  if (length(list) == 1) {
    // I was unable to get this to work properly. A copy of the single element
    // is returned, but the element is not removed from the list.
    //
    // Also, I tried to use free() here, including indirectly by trying the
    // line "return pop(&list);", but it always seemed to result in a
    // segmentation fault happening later on in the program's execution.
    listElement* dequeued = createEl(list->data, sizeof(*(list->data)));
    list = NULL;
    return dequeued;
  }
  listElement* current = list;
  // This will leave current at the second-last element.
  while (current->next->next != NULL) {
    current = current->next;
  }

  // Creates a new element with the same values as the tail element.
  listElement* dequeued = createEl(current->next->data, sizeof(*(current->next->data)));

  deleteAfter(current);
  return dequeued;
}

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  void* dataPointer = malloc(sizeof(void)*size);
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
    current->print(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size){
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
