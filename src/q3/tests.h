#ifndef CT331_ASSIGNMENT_TESTS
#define CT331_ASSIGNMENT_TESTS

typedef int (*testFunction)();

void runTests();

// Prototypes of my test functions.
void printTestResults(testFunction test, char* testDescription);
//
void printInt(void* intToPrint);
void printChar(void* charToPrint);
void printFloat(void* floatToPrint);
void printDouble(void* doubleToPrint);

#endif
