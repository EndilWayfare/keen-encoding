#ifndef KEEN_CODES_H

#pragma once

#define ALPHABET_LENGTH 26

typedef int (*Encoder) (const char *message, char *out);
typedef int(*LengthCalculator) (const char *message);

struct Code
{
     const char *name;   /**< "nice name", used for user feedback */
     const char *handle; /**< code-friendly identifier. The 'slug' */
     Encoder encode;     /**< pointer to function used to encode message */
     LengthCalculator calcLength; /**< pointer to function that calculates length of encoded message */
     // add 'description' member at some point?
};
typedef struct Code Code;

/**
* Example Code struct. Used as default code for now, probably until
* I implement the roll cipher.
*/
extern Code allCaps;

/**
* Example encoder, with compatible signature, used for testing
*
* Like most encoders, DOES NOT CHECK LENGTH OF OUTPUT BUFFER
* It is the responsibility of the caller to verify adequate capacity.
* Use 'calcLengthAllCaps' for convenience.
* 
* @param in The string containing message to be encoded
* @param out The destination buffer for encoded message
* @return The number of characters written to 'out', NOT including null
*/
int encodeAllCaps(const char *message, char *out);

/**
* Calculates necessary space to store result of 'AllCaps' code
* given a certain English input buffer.
* Includes space for the null terminator.
*
* @param source The string containing the message to be encoded
* @return The number of chars needed to store encoded message
*/
int calcLengthAllCaps(const char *message);

#endif // !KEEN_CODES_H