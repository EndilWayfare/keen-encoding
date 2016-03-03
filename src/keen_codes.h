#ifndef KEEN_CODES_H

#pragma once

#define ALPHABET_LENGTH 26

typedef int (*Encoder) (const char *in, char *out);

/**
* Example encoder, with compatible signature, used for testing
* Like most encoders, DOES NOT CHECK LENGTH OF OUTPUT BUFFER
* It is the responsibility of the caller to verify adequate capacity.
* Use 'calcLengthAllCaps' for convenience.
*/
int encodeAllCaps(const char *in, char *out);

/**
* Calculates necessary space to store result of 'AllCaps' code
* given a certain English input buffer.
* Includes space for the null terminator.
*
* @param source The string containing the message to be encoded
*/
int calcLengthAllCaps(const char *source);

#endif // !KEEN_CODES_H