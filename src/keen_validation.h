#ifndef KEEN_VALIDATION_H
#define KEEN_VALIDATION_H

#pragma once

#include <stdbool.h>

/*! Euclid's algorithm for determining Greatest Common Divisor */
int calcGCD(int a, int b);

/*! Determines if 1 is the ONLY number that can cleanly divide both integers */
bool isCoprime(int a, int b);

#endif // !KEEN_VALIDATION_H
