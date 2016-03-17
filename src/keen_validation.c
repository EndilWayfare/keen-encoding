/*============================================================================

  File: keen_validation.c

  Purpose: Making sure values are what they're suposed to be

  Creator: Philip Ormand

  Date Created: 2016-03-17

============================================================================*/

#include "keen_validation.h"

/*! Euclid's algorithm for determining Greatest Common Divisor */
int calcGCD(int a, int b)
{
     int swap;

     // a must be greater than b
     if (a < b)
     {
          swap = a;
          a = b;
          b = swap;
     }

     do
     {
          a %= b;
          swap = a;
          a = b;
          b = swap;
     } while (b);

     return a;
}

bool isCoprime(int a, int b)
{
     return calcGCD(a, b) == 1;
}