
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "keen_codes.h"

int compareCodePtrs(const void *code1, const void *code2)
{
     // compare the string values of the code handles
     // those are the 'unique identifiers' most like a primary key
     int cmp = strcmp( (*(Code **)code1)->handle, (*(Code **)code2)->handle );

     if (cmp == 0)
     {
          fputs("Two compared Code structs have identical handles."
                "This is probably wrong.", stderr);
     }

     return cmp;
}


// 'All Caps' - not much of a code, but a pretty similar transformation
Code allCaps = { "All Caps", "allcaps", encodeAllCaps, calcLengthAllCaps };

int encodeAllCaps(const char * message, char * out)
{
     const char *readHead;
     char *writeHead;
     
     for (readHead = message, writeHead = out;
     *readHead != 0; ++readHead, ++writeHead)
     {
          *writeHead = toupper(*readHead);
     }
     *++writeHead = 0;
     
     return writeHead - out;
}

int calcLengthAllCaps(const char * message)
{
     // strlen doesn't include the null terminator.
     // make sure there's at least one more space.
     return strlen(message) + 1;
}
