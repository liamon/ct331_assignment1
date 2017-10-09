#ifndef CT331_ASSIGNMENT_GENERIC_LINKED_LIST
#define CT331_ASSIGNMENT_GENERIC_LINKED_LIST

typedef void (*printData)(void*); // Function pointer.

typedef struct genericListElementStruct{
  void* data;
  printData print;
  size_t size;
  struct genericListElementStruct* next;
} genericListElement;

// Returns the number of elements in a linked list.
int length(genericListElement* list);

// Push a new element onto the head of a list.
// Update the list reference using side effects.
void push(genericListElement** list, void* data, size_t size, printData print);

// Pop an element from the head of a list.
// Update the list reference using side effects.
genericListElement* pop(genericListElement** list);

// Enqueue a new element onto the head of the list.
// Update the list reference using side effects.
void enqueue(genericListElement** list, void* data, size_t size, printData print);

// Dequeue an element from the tail of the list.
genericListElement* dequeue(genericListElement* list);

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericListElement* createEl(void* data, size_t size, printData print);

//Prints out each element in the list
void traverse(genericListElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
genericListElement* insertAfter(genericListElement* after, void* data, size_t size, printData print);

//Delete the element after the given el
void deleteAfter(genericListElement* after);

#endif
