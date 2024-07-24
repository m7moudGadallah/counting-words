#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Read input from a file and return it as a buffer
 *
 * @param file_path The path to the file to read.
 * @return char* Returns a pointer to the buffer containing the file content.
 *         Returns NULL if the file could not be read.
 */
char *read_from_file(const char *file_path);

/**
 * @brief Read input from stdin and return it as a buffer
 *
 * @return char* Returns a pointer to the buffer containing the stdin content.
 *         Returns NULL if an error occurred.
 */
char *read_from_stdin();

#endif // INPUT_HANDLING_H