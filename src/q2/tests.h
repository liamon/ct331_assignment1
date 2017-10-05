#ifndef CT331_ASSIGNMENT_TESTS
#define CT331_ASSIGNMENT_TESTS

typedef int (*testFunction)();

void runTests();

// Prototypes of my test functions.
void printTestResults(testFunction test, char* testDescription);
//
// The actual tests:
int testPushToEmptyList();
int testEnqueueToEmptyList();
int testPushToExistingList();
int testEnqueueToExistingList();

int testDequeueFromEmptyList();
int testDequeueWhichEmptiesList();
int testDequeue();

#endif
