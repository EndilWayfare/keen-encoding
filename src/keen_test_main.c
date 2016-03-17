
#include <stdio.h>
#include "keen_codes.h"
#include "keen_io.h"
#include "keen_validation.h"

void printAllCodeNames(const Code *arr[], const Code ** const end)
{
     // Use arr as 'iterator', because we don't need to return length
     while (arr != end)
     {
          printf("\"%s\" (%s)", (*arr)->name, (*arr)->handle );
          arr++;
     }
}

void testCodeSorting()
{
     // Does my fiendishly ingenious qsorting of codes work properly?

     Code lolz = { "Lolz", "lolz", allCaps.encode, allCaps.calcLength };
     Code swagMaster = { "Swag Master", "swagmaster", allCaps.encode, allCaps.calcLength };
     Code aaa = { "AAA", "aaa", allCaps.encode, allCaps.calcLength };
     Code zebra = { "Zebra Haha", "zebra", allCaps.encode, allCaps.calcLength };
     Code x = { "Mysterious Mr. X", "mysteryx", allCaps.encode, allCaps.calcLength };

     Code *codeArray[] = {
          &lolz,
          &x,
          &swagMaster,
          &zebra,
          &aaa,
     };

     size_t codePtrLength = sizeof(Code*);
     size_t codeArrayLength = sizeof(codeArray) / codePtrLength;

     puts("BEFORE SORTING:");
     printAllCodeNames(codeArray, codeArray + codeArrayLength);

     puts("\nAFTER SORTING:");
     qsort(codeArray, codeArrayLength, codePtrLength, compareCodePtrs);
     printAllCodeNames(codeArray, codeArray + codeArrayLength);
}

void testGCDImplementation(int a, int b, int expectedDivisor)
{
     int GCD = calcGCD(a, b);
     printf("The GCD of %d and %d is calculated to be %d\n", a, b, GCD);
     
     if (GCD == expectedDivisor)
     {
          puts("...which is exactly what we predicted, so that's good.\n");
     }
     else
     {
          printf("...but we thought it should be %d, so something went wrong.\n\n", expectedDivisor);
     }
}

void testIsCoprime(int a, int b, bool expectedAnswer)
{
     bool coprime = isCoprime(a, b);
     
     printf("%d and %d are %scoprime.\n", a, b,
            (coprime) ? "" : "not ");

     if (coprime == expectedAnswer)
     {
          puts("...which is exactly what we predicted, so that's good.\n");
     }
     else
     {
          printf("...but we thought they %s, so something went wrong.\n\n",
                 (coprime) ? "were" : "weren't");
     }
}

int main()
{
     testGCDImplementation(15, 26, 1);
     testGCDImplementation(21, 12, 3);

     testIsCoprime(15, 26, true);
     testIsCoprime(21, 12, false);

     return 0;
}