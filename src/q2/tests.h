#ifndef CT331_ASSIGNMENT_TESTS
#define CT331_ASSIGNMENT_TESTS

void runTests();

// Prototypes of my test functions.
void printTestResults(int isTestSuccess, char* testDescription);

int testPushToEmptyList();
int testEnqueueToEmptyList();
int testPushToExistingList();
int testEnqueueToExistingList();

#endif
