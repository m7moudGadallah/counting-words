#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *data;
    int size;
    int capacity;
} ReadBuffer;

/**
 * @brief Create a new read buffer with initial size.
 *
 * @return ReadBuffer* Returns a pointer to the newly created ReadBuffer.
 *         Returns NULL if memory allocation fails.
 */
ReadBuffer *create_read_buffer();

/**
 * @brief Free the memory associated with a ReadBuffer.
 *
 * @param buffer Pointer to the ReadBuffer to be freed.
 */
void free_read_buffer(ReadBuffer *buffer);

/**
 * @brief Append a character to the ReadBuffer.
 *
 * @param buffer Pointer to the ReadBuffer.
 * @param c The character to append.
 * @return int Returns 0 on success. Returns -1 if memory reallocation fails.
 */
int append_to_buffer(ReadBuffer *buffer, char c);

/**
 * @brief Read input from a file and return it as a buffer
 *
 * @param file_path The path to the file to read.
 * @return ReadBuffer* Returns a pointer to the buffer containing the file
 * content. Returns NULL if the file could not be read.
 */
ReadBuffer *read_from_file(const char *file_path);

/**
 * @brief Read input from stdin and return it as a buffer
 *
 * @return char* Returns a pointer to the buffer containing the stdin content.
 *         Returns NULL if an error occurred.
 */
ReadBuffer *read_from_stdin();

#endif // INPUT_HANDLING_H