/***********************************************************************
*
* File: keen.c
* 
* Purpose: The primary file for execution, containing the main function
* 
* Creator: Philip Ormand
*
* Date Updated: 2016-03-02
*
***********************************************************************/

#include <stddef.h>
#include <stdio.h>

#include "keen_codes.h"
#include "keen_io.h"

int main()
{
     char inputString[BUFFER_SIZE] = { 0 },
          outputString[BUFFER_SIZE] = { 0 };
     int ch = 0;

     puts("Please enter a messge to encode: ");
     readString(inputString, inputString + BUFFER_SIZE);

     puts("\nInput Message:\n");
     puts(inputString);

     int length = calcLengthAllCaps(inputString);

     // validation block for encoding. Make sure output buffer is large enough
     if (length <= sizeof(outputString))
     {
          encodeAllCaps(inputString, outputString);

          puts("\n\nOutput Message:\n");
          puts(outputString);
     }
     else
     {
          fputs("\nERROR: Not enough space to hold encoded message.", stderr);
     }
     

     return 0;
}