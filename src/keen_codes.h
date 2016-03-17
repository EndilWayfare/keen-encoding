#ifndef KEEN_CODES_H
#define KEEN_CODES_H

#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_LENGTH 26

enum CodeMode
{
     ENCODE = 0,  /*!< 0, so 'ENCODE' is default behavior */
     DECODE,
};
typedef enum CodeMode CodeMode;

union Key
{
     int i;
     char* str; /*!< encoders that use a string key should pass source message with
                no change if they are passed the nullptr */
};

struct CodeParams
{
     union Key key;
     union Key secondaryKey;
     CodeMode mode;
};
typedef struct CodeParams CodeParams;

// initializer for default CodeParams struct. No key, mode set to ENCODE.
#define CODE_PARAMS_DEFAULT {0}  // usage: CodeParams myParams = CODE_PARAMS_DEFAULT

typedef int (*Encoder) (const char *message, char *out, CodeParams *params);
typedef int(*LengthCalculator) (const char *message);

struct Code
{
     const char *name;   /*!< "nice name", used for user feedback */
     const char *handle; /*!< code-friendly identifier. The 'slug' */
     Encoder encode;     /*!< pointer to function used to encode message */
     LengthCalculator calcLength; /*!< pointer to function that calculates length of encoded message */
     // add 'description' member at some point?
};
typedef struct Code Code;

/**
 * Compares two Code struct pointers to determine natural ordering.
 * Intended primarily as an argument for qsort.
 * 
 * @param code1 Pointer to one Code struct instance
 * @param code2 Pointer to another Code struct instance
 */
int compareCodePtrs(const void *code1, const void *code2);

/**
* Example Code struct. Used as default code for testing. It's silly, and will pro
*/
extern Code allCaps;

/**
 * The Ceaser cipher: Simple shift cipher that offsets each message letter by a
 * certain number of positions to the right in the alphabet. With a shift of 5,
 * 'A' becomes 'F'. With a shift of -1, 'A' becomes 'Z'.
 *
 * https://en.wikipedia.org/wiki/Caesar_cipher
 */
extern Code caesar;

/**
 * The Affine cipher: Shift cipher with two coefficients. The letter to be encoded
 * is multiplied by the first key and added to the second key. The Caesar cipher can
 * be thought of as an affine cipher that always has a first key of 0, since it is a
 * simple additive translation.
 */
extern Code affine;

#endif // !KEEN_CODES_H