#ifndef CT331_ASSIGNMENT_TESTS
#define CT331_ASSIGNMENT_TESTS

typedef int (*testFunction)();

void runTests();

// Prototypes of my test functions.
void printTestResults(testFunction test, char* testDescription);
//
// The actual tests:
int testEnqueueAndPush();
int testPopFromEmptyList();
int testPop();
void testGenericness();
//
// These are printData variables:
void printInt(void* intToPrint);
void printChar(void* charToPrint);
void printDouble(void* doubleToPrint);
void printString(void* stringToPrint);

#endif
