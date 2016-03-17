/*============================================================================

  File: keen_codes.c

  Purpose: Defines behavior of Code struct and individual encoding methods.

  Creator: Philip Ormand

  Date Created: 2016-03-04

============================================================================*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "keen_codes.h"
#include "keen_validation.h"

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
* DOES NOT CHECK LENGTH OF OUTPUT BUFFER
* The caller is responsible for verifying adequate capacity.
* Use 'calcLengthAllCaps' for convenience.
*
* @param in The string containing message to be encoded - must be null-terminated
* @param out The destination buffer for encoded message
* @param params Options for encoding
* @return The number of characters written to 'out', NOT including null
*/
int encodeAllCaps(const char * message, char * out, CodeParams *params)
{
     const char *readHead = message;
     char *writeHead = out;
     
     // Always read from 'message' at least once, even if the value is 0
     do
     {
          *writeHead++ = toupper(*readHead);
     } while (*++readHead); // stop reading when new value is 0
     
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
* Encoder for the Caesar cipher
*
* DOES NOT CHECK LENGTH OF OUTPUT BUFFER
* The caller is responsible for verifying adequate capacity.
* Use 'calcLengthCaesar' for convenience.
*
* @param in The string containing message to be encoded - must be null-terminated
* @param out The destination buffer for encoded message
* @param params Options for encoding
* @return The number of characters written to 'out', NOT including null
*/
int encodeCaesar(const char * message, char * out, CodeParams *params)
{
     const char *readHead = message;
     char *writeHead = out;
     signed char ch = *readHead;

     do
     {
          if ( isalpha(ch) )
          {
               // subtract 'a' from character to get offset from beginning of alphabet,
               // 'A' for capital letters, 'a' for lowercase
               int caseOffset = (isupper(*readHead)) ? 'A' : 'a';
               ch -= caseOffset;

               // add offset from 'key', rolling back to beginning of alphabet if >26
               ch = (ch + params->key.i) % ALPHABET_LENGTH;

               // apply offset, bringing ch back to ASCII range
               ch += caseOffset;
          }
          
          *writeHead++ = ch;

     } while (ch = *++readHead);

     return writeHead - out;
}

/**
* Calculates necessary space to store result of 'Caesar' code
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

// 'Affine' cipher
/**
* Example encoder, with compatible signature, used for testing
*
* DOES NOT CHECK LENGTH OF OUTPUT BUFFER
* The caller is responsible for verifying adequate capacity.
* Use 'calcLengthAffine' for convenience.
*
* @param in The string containing message to be encoded - must be null-terminated
* @param out The destination buffer for encoded message
* @param params Options for encoding
* @return The number of characters written to 'out', NOT including null
*/
int encodeAffine(const char * message, char * out, CodeParams *params)
{
     const char *readHead = message;
     char *writeHead = out;
     signed char ch = *readHead;

     if ( !isCoprime(params->key.i, params->secondaryKey.i) )
     {
          fputs("ERROR: The two keys are not coprime. The message has been encoded,"
                "but cannot be reliably decoded.", stderr);
     }

     do
     {
          if (isalpha(ch))
          {
               // subtract 'a' from character to get offset from beginning of alphabet,
               // 'A' for capital letters, 'a' for lowercase
               int caseOffset = (isupper(*readHead)) ? 'A' : 'a';
               ch -= caseOffset;

               // multiply by first key then add second key,
               // rolling back to beginning of alphabet if >26
               ch = (ch * params->key.i + params->secondaryKey.i) % ALPHABET_LENGTH;

               // apply offset, bringing ch back to ASCII range
               ch += caseOffset;
          }

          *writeHead++ = ch;

     } while (ch = *++readHead);

     return writeHead - out;
}

/**
* Calculates necessary space to store result of 'Affine' code
* given a certain English input buffer.
* Includes space for the null terminator.
*
* @param source The string containing the message to be encoded
* @return The number of chars needed to store encoded message
*/
int calcLengthAffine(const char *message)
{
     return CALC_LENGTH_SAME_AS_SOURCE;
}

Code affine = { "Affine Cipher", "affine", encodeAffine, calcLengthAffine };


// Array of all currently implemented codes
Code* codes[] =
{
     &allCaps,
     &affine,
     &caesar,
};