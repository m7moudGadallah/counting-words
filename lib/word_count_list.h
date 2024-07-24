#ifndef WORD_COUNT_LIST
#define WORD_COUNT_LIST

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Word count node structure for word count linked list
typedef struct word_count_node {
    char *word;
    int count;
    struct word_count_node *next;
} WCNode;

/**
 * @brief Find a word count node for a given word
 *
 * @param head Head of the word count list
 * @param word Word to search for it
 * @return WCNode* Returns pointer to node if it exists, otherwise returns NULL
 */
WCNode *find_wc_node(const WCNode *head, const char *word);

/**
 * @brief Create a new word count node for a given word
 *
 * @param word Word to be stored in the node.
 * @return WCNode* Returns a pointer to the newly created node
 */
WCNode *create_wc_node(const char *word);

/**
 * @brief Insert a new word count node or update the count of an existing one in
 * the word count list.
 *
 * - This function searches for the given word in the list. If found, it
 * increments the count of the existing node. If not found, it creates a new
 * node with the word and appends it to the list.
 *
 * @param head Pointer to head of the word count list.
 * @param word Word to insert or update.
 * @return WCNode* Returns a pointer to the node of the given word.
 */
WCNode *insert_or_update_wc_node(WCNode **head, const char *word);

/**
 * @brief Sort word count list
 *
 * @param head Pointer to head of word count list
 * @param comp_fn_ptr  Pointer to compare function
 * @return void
 */
void sort_wc_list(WCNode **head,
                  int (*comp_fn_ptr)(WCNode *node1, WCNode *node2));

/**
 * @brief Print word count list.
 *
 * @param head Head of the word count list.
 * @param reverse Option to print list forward or backward, true means backward
 * otherwise means forward
 * @return void
 */
void print_list(const WCNode *head, bool reverse);

/**
 * @brief Free word count list
 *
 * @param head Head of the word count list
 * @return void
 */
void free_list(WCNode *head);

#endif // WORD_COUNT_LIST