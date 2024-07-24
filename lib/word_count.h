#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include "word_count_list.h"
#include <stdlib.h>

/**
 * @brief Count number of words string buffer.
 *
 * @param buffer String we need to count words in it.
 * @return int Returns number of words.
 */
int count_words(const char *buffer);

/**
 * @brief Count word frequencies and update the word count list.
 *
 * This function processes the input buffer, counts the frequency of each word,
 * updates the word count list, and returns a pointer to the head of the list.
 *
 * @param buffer String to count word frequencies in.
 * @param head Pointer to the head of the word count list.
 * @return WCNode* Returns a pointer to the head of the word count list.
 */
WCNode *count_word_frequencies(const char *buffer, WCNode **head);

#endif // WORD_COUNT_H