#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

// Returns the number of elements in a linked list.
int length(genericListElement* list) {
  int lengthCounter = 0;
  genericListElement* current = list; // This avoids side effects changing list.
  while (current != NULL) {
    lengthCounter++;
    current = current->next;
  }
  return lengthCounter;
}

// Push a new element onto the head of a list.
// Update the list reference using side effects.
void push(genericListElement** list, void* data, size_t size, printData print) {
  genericListElement* newElement = createEl(data, size, print);
  // By dereferencing list once, it is now a pointer to a genericListElement.
  newElement->next = *list;
  *list = newElement; // Side effects.
}

// Pop an element from the head of a list.
// Update the list reference using side effects.
genericListElement* pop(genericListElement** list) {
  // The bulk of this method requires there to be at least one element, so
  // I have to deal with the special case by returning the empty list.
  if (length(*list) == 0) {
    return *list;
  }

  genericListElement* head = *list;
  // Create a new element with the same values as the first element.
  genericListElement* poppedElement = createEl(head->data, sizeof(*(head->data)), head->print);
  *list = head->next;

  free(head->data);
  free(head);
  return poppedElement;
}

// Enqueue a new element onto the head of a list.
// Update the list reference using side effects.
void enqueue(genericListElement** list, void* data, size_t size, printData print) {
  // This has the same effect as push, so...
  push(list, data, size, print);
}

// Dequeue an element from the tail of the list.
genericListElement* dequeue(genericListElement* list) {

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
    genericListElement* dequeued = createEl(list->data, sizeof(*(list->data)), list->print);
    list = NULL;
    return dequeued;
  }
  genericListElement* current = list;
  // This will leave current at the second-last element.
  while (current->next->next != NULL) {
    current = current->next;
  }

  // Creates a new element with the same values as the tail element.
  genericListElement* dequeued = createEl(current->next->data, sizeof(*(current->next->data)), current->next->print);

  deleteAfter(current);
  return dequeued;
}

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericListElement* createEl(void* data, size_t size, printData print) {
  genericListElement* e = malloc(sizeof(genericListElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  void* dataPointer = malloc(sizeof(void*)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  e->print = print;
  memmove(dataPointer, data, sizeof(void*) * size);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(genericListElement* start){
  genericListElement* current = start;
  while(current != NULL){
    current->print(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
genericListElement* insertAfter(genericListElement* el, void* data, size_t size, printData print){
  genericListElement* newEl = createEl(data, size, print);
  genericListElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(genericListElement* after){
  genericListElement* delete = after->next;
  genericListElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}
