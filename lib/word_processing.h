#ifndef WORD_PROCESSING_H
#define WORD_PROCESSING_H

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Check if a character is a word terminator.
 *
 * Word terminators are defined as: ' ', '\n', '\t', '\0', ',', '!', '?'.
 *
 * @param c The character to check.
 * @return bool Returns true if the character is a word terminator, otherwise
 * false.
 */
bool is_word_terminator(char c);

/**
 * @brief Get the length of the next word in a buffer of chars.
 *
 * Iterate over a buffer of chars and keep counting chars until a word
 * terminator is reached.
 *
 * Word terminators are defined as: ' ', '\\n', '\t', and '\0'.
 *
 * @param buffer The buffer to iterate over.
 * @return int Returns the length of the next word.
 */
int get_word_len(const char *buffer);

/**
 * @brief Extract a word (substring) from a buffer of chars.
 *
 * Allocate a new buffer and copy chars from the buffer to it.
 *
 * @param buffer The buffer to extract the word from.
 * @param word_len The length of the word.
 * @return char* Returns the extracted word.
 */
char *extract_word(const char *buffer, int word_len);

/**
 * @brief Convert word characters to lowercase.
 *
 * @param word The word to convert.
 * @return void
 */
void to_lowercase(char *word);

#endif // WORD_PROCESSING_H
