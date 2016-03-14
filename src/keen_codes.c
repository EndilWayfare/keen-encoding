
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

/**
 * Default for LengthCalculator functions: the same length as source message
 * strlen doesn't include the null terminator; make sure there's room for one more char.
 */
#define CALC_LENGTH_SAME_AS_SOURCE strlen(message) + 1

// 'All Caps' code
/**
* Example encoder, with compatible signature, used for testing
*
* 'message' must be null-terminated
*
* DOES NOT CHECK LENGTH OF OUTPUT BUFFER
* It is the responsibility of the caller to verify adequate capacity.
* Use 'calcLengthAllCaps' for convenience.
*
* @param in The string containing message to be encoded
* @param out The destination buffer for encoded message
* @param params Options for encoding
* @return The number of characters written to 'out', NOT including null
*/
int encodeAllCaps(const char * message, char * out, CodeParams *params)
{
     const char *readHead = message;
     char *writeHead = out;
     
     while (*readHead)
     {
          *writeHead++ = toupper(*readHead++);
     }

     *writeHead = 0; // null-terminate 'out'
     
     return writeHead - out;
}

/**
* Calculates necessary space to store result of 'AllCaps' code
* given a certain English input buffer.
* Includes space for the null terminator.
*
* @param source The string containing the message to be encoded
* @return The number of chars needed to store encoded message
*/
int calcLengthAllCaps(const char * message)
{
     return CALC_LENGTH_SAME_AS_SOURCE;
}

Code allCaps = { "All Caps", "allcaps", encodeAllCaps, calcLengthAllCaps };


// 'Caesar' cipher
/**
* Example encoder, with compatible signature, used for testing
*
* Like most encoders, DOES NOT CHECK LENGTH OF OUTPUT BUFFER
* It is the responsibility of the caller to verify adequate capacity.
* Use 'calcLengthAllCaps' for convenience.
*
* @param in The string containing message to be encoded
* @param out The destination buffer for encoded message
* @param params Options for encoding
* @return The number of characters written to 'out', NOT including null
*/
int encodeCaesar(const char * message, char * out, CodeParams *params)
{
     const char *readHead = message;
     char *writeHead = out;
     signed char ch = 0;

     while (ch = *readHead++)
     {
          if ( isalpha(ch) )
          {
               // subtract 'a' from character to get offset from beginning of alphabet,
               // 'A' for capital letters, 'a' for lowercase
               int caseOffset = (isupper(*readHead)) ? 'A' : 'a';
               ch -= caseOffset;

               // add offset from 'key', rolling back to beginning of alphabet if >26
               ch += params->key.i % ALPHABET_LENGTH;

               // apply offset, bringing ch back to ASCII range
               ch += caseOffset;
          }
          
          *writeHead++ = ch;
     }

     *writeHead = 0; // null-terminate 'out'

     return writeHead - out;
}

/**
* Calculates necessary space to store result of 'AllCaps' code
* given a certain English input buffer.
* Includes space for the null terminator.
*
* @param source The string containing the message to be encoded
* @return The number of chars needed to store encoded message
*/
int calcLengthCaesar(const char *message)
{
     return CALC_LENGTH_SAME_AS_SOURCE;
}

Code caesar = { "Caesar Cipher", "caesar", encodeCaesar, calcLengthCaesar };


// Array of all currently implemented codes
Code* codes[] =
{
     &allCaps,
     &caesar,
};