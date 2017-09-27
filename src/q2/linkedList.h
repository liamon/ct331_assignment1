#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;

// Returns the number of elements in a linked list.
int length(listElement* list);

// Push a new element onto the head of a list.
// Update the list reference using side effects.
void push(listElement** list, char* data, size_t size);

// Pop an element from the head of a list.
// Update the list reference using side effects.
listElement* pop(listElement** list);

// Enqueue a new element onto the head of the list.
// Update the list reference using side effects.
void enqueue(listElement** list, char* data, size_t size);

// Dequeue an element from the tail of the list.
listElement* dequeue(listElement* list);

#endif
