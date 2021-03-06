#ifndef CT331_ASSIGNMENT_TESTS
#define CT331_ASSIGNMENT_TESTS

typedef int (*testFunction)();

void runTests();

// Prototypes of my test functions.
void printTestResults(testFunction test, char* testDescription);
//
// The actual tests:
int testLengthEmpty();
int testLength();
//
int testPushToEmptyList();
int testEnqueueToEmptyList();
int testPushToExistingList();
int testEnqueueToExistingList();
//
int testDequeueFromEmptyList();
int testDequeueWhichEmptiesList();
int testDequeue();
//
int testPopFromEmptyList();
int testPopWhichEmptiesList();
int testPop();

#endif
