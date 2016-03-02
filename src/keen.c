/***********************************************************************
*
* File: keen.c
* 
* Purpose: The primary file for execution, containing the main function
* 
* Developer: Philip Ormand
*
* Date Updated: 2016-03-02
*
***********************************************************************/

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

#define BUFFER_SIZE 265

int main()
{
     char inputString[BUFFER_SIZE] = { 0 },
          *inputStringEnd = inputString + BUFFER_SIZE,
          outputString[BUFFER_SIZE] = { 0 },
          *readHead = inputString,
          *writeHead = outputString;
     int ch = 0;

     while ( readHead != inputStringEnd - 1 && (ch = getchar()) >= 0 && ch != '\n' )
     {
          *readHead++ = (char) ch;
     }

     if (readHead == inputStringEnd - 1)
     {
          *readHead = 0;
     }

     puts("\nInput Message:\n");
     puts(inputString);

     for (readHead = inputString; *readHead != 0; ++readHead, ++writeHead)
     {
          *writeHead = toupper(*readHead);
     }
     *++writeHead = 0;

     puts("\n\nOutput Message:\n");
     puts(outputString);

     return 0;
}