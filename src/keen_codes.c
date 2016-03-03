
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "keen_codes.h"

int encodeAllCaps(const char * in, char * out)
{
     const char *readHead;
     char *writeHead;
     
     for (readHead = in, writeHead = out;
     *readHead != 0; ++readHead, ++writeHead)
     {
          *writeHead = toupper(*readHead);
     }
     *++writeHead = 0;
     
     return 0;
}

int calcLengthAllCaps(const char * source)
{
     // strlen doesn't include the null terminator.
     // make sure there's at least one more space.
     return strlen(source) + 1; 
}
