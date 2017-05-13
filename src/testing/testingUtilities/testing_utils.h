/**
 * Testing utilities to improve unit tests
 */
#ifndef TESTING_UTILITIES_H
#define TESTING_UTILITIES_H

#include <stdint.h>

/**
 * Seeds pseudo-random generator
 */
void initiateTestingUtilities(void);

/**
 * Generates a randomised uint8_t value
 */
uint8_t testingUtils_GetRandomUint8(void);

#endif
