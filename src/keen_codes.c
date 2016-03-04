
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "keen_codes.h"

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
