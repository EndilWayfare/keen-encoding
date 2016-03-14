
#include <stdio.h>
#include "keen_codes.h"
#include "keen_io.h"

void printAllCodeNames(const Code *arr[], const Code ** const end)
{
     // Use arr as 'iterator', because we don't need to return length
     while (arr != end)
     {
          printf("\"%s\" (%s)", (*arr)->name, (*arr)->handle );
          arr++;
     }
}

int main()
{
     // Does my fiendishly ingenious qsorting of codes work properly?

     Code lolz = { "Lolz", "lolz", encodeAllCaps, calcLengthAllCaps };
     Code swagMaster = { "Swag Master", "swagmaster", encodeAllCaps, calcLengthAllCaps };
     Code aaa = { "AAA", "aaa", encodeAllCaps, calcLengthAllCaps };
     Code zebra = { "Zebra Haha", "zebra", encodeAllCaps, calcLengthAllCaps };
     Code x = { "Mysterious Mr. X", "mysteryx", encodeAllCaps, calcLengthAllCaps };

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

     return 0;
}