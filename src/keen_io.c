
#include <stdio.h>
#include "keen_io.h"

int readString(char * const buffer, const char * const end) 
// top-level const for both parameters. Address of pointers can't change.
// low-level const for end. Pointer not intended for writing. 
{
     char *writeHead = buffer; // might as well have a descriptive name...
     int ch = 0;
     
     if (buffer == end)
     {
          // no writable space in buffer. Return failure code.
          return -1;
     }

     while ( writeHead != end - 1    // still at least 1 away from last writable element
             && (ch = getchar()) > 0 // getchar was sucessfull, and not the null character
             && ch != '\n' )         // stop read after encountering newline
     {
          *writeHead++ = (char) ch;
     }
     
     // null-terminate the string. If 'end' argument is valid, there should aways be room.
     *writeHead = 0;

     return writeHead - buffer; // return number of characters written
}
