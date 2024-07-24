#include "word_count_list.h"

WCNode *create_wc_node(const char *word) {
    WCNode *node = (WCNode *)malloc(sizeof(WCNode));

    if (node == NULL) {
        perror("Error allocating new word count node");
        return NULL;
    }

    node->word = strdup(word);
    node->count = 1;
    node->next = NULL;

    return node;
}

WCNode *find_wc_node(const WCNode *head, const char *word) {
    if (head == NULL || word == NULL || *word == '\0')
        return NULL;

    while (head) {
        if (strcmp(head->word, word) == 0)
            return (WCNode *)head;
        head = head->next;
    }

    return NULL;
}

WCNode *insert_or_update_wc_node(WCNode **head, const char *word) {
    WCNode *existing_node = find_wc_node(*head, word);

    if (existing_node != NULL) {
        existing_node->count++;
        return existing_node;
    }

    WCNode *new_node = create_wc_node(word);

    if (new_node == NULL)
        return NULL;

    if (*head == NULL)
        *head = new_node;
    else {
        WCNode *current = *head;

        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    return new_node;
}

void print_list(const WCNode *head) {
    while (head) {
        printf("%s: %d\n", head->word, head->count);
        head = head->next;
    }
}

void free_list(WCNode *head) {
    while (head) {
        WCNode *next = head->next;
        free(head->word);
        free(head);
        head = next;
    }
}