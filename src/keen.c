/*============================================================================

  File: keen.c

  Purpose: The primary file for execution, containing the main function

  Creator: Philip Ormand

  Date Created: 2016-03-02

============================================================================*/

#include <stddef.h>
#include <stdio.h>

#include "keen_codes.h"
#include "keen_io.h"

int main()
{
     char inputString[BUFFER_SIZE] = { 0 },
          outputString[BUFFER_SIZE] = { 0 };
     Code *code = &affine;
     CodeParams params = CODE_PARAMS_DEFAULT;

     puts("Please enter a messge to encode: ");
     readString(inputString, inputString + BUFFER_SIZE);

     puts("\nPlease enter the multiplying offset: ");
     scanf(" %d", &params.key.i);

     puts("\nPlease enter the adding offset: ");
     scanf(" %d", &params.secondaryKey.i);

     /*
     puts("\nInput Message:");
     puts(inputString);
     */

     printf("\nCode to use: '%s'\n", code->name);

     int encodedLength = code->calcLength(inputString);

     // validation block for encoding. Make sure output buffer is large enough
     if (encodedLength <= sizeof(outputString))
     {
          code->encode(inputString, outputString, &params);

          puts("\nOutput Message:");
          puts(outputString);
     }
     else
     {
          fputs("\nERROR: Not enough space to hold encoded message.", stderr);
     }

     return 0;
}