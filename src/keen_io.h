#ifndef KEEN_IO_H
#define KEEN_IO_H

#pragma once

#define BUFFER_SIZE 265

/**
 * Reads a string from stdin into buffer, until encountering newline or reaching 
 * next-to-last index in buffer. If buffer has length of 1, it will always
 * contain the empty string.
 *
 * fgets is super annoying, because it includes the \n in the input string.
 * also, I may want additional custom functionality in the future.
 * 
 * @param buffer Pointer to the string buffer receiving input
 * @param end Pointer to one-off-the-end element of buffer
 * @return The number of characters read, NOT including the null character.
 *         If there is no space in buffer, returns -1
 */
int readString(char *buffer, const char * const end);

#endif // !KEEN_IO_H
