#ifndef WORD_COUNT_LIST
#define WORD_COUNT_LIST

#include<stdio.h>
#include<stdlib.h>

// Word count node structure for word count linked list
typedef struct word_count_node {
    char *word;
    int count;
    struct word_count_node *next;
} WCNode;

/**
 * @brief Create a new word count node for a given word
 *
 * @param word Word to be stored in the node.
 * @return WCNode* Returns a pointer to the newly created node
 */
WCNode *create_wc_node(char *word);

/**
 * @brief Insert a new word count node or update the count of an existing one in
 * the word count list.
 *
 * - This function searches for the given word in the list. If found, it
 * increments the count of the existing node. If not found, it creates a new
 * node with the word and appends it to the list.
 *
 * @param head Head of the word count list.
 * @param word Word to insert or update.
 * @return WCNode* Returns a pointer to the node of the given word.
 */
WCNode *insert_or_update_wc_node(WCNode *head, const char *word);

/**
 * @brief Print word count list.
 * 
 * @param head Head of the word count list.
 * @return void
 */
void print_list(const WCNode *head);

/**
 * @brief Free word count list
 * 
 * @param head Head of the word count list
 * @return void
 */
void free_list(WCNode *head);

#endif // WORD_COUNT_LIST