#include "word_count.h"

int count_words(const char *buffer) {
    if (buffer == NULL || *buffer == '\0')
        return 0;

    int count = 0;

    while (*buffer) {
        if (is_word_terminator(*buffer)) {
            ++buffer;
        } else {
            ++count;
            buffer += get_word_len(buffer);
        }
    }
    return count;
}

WCNode *count_word_frequencies(const char *buffer, WCNode *head) {
    if (buffer == NULL || *buffer == '\0') {
        return head;
    }

    while (*buffer) {
        if (is_word_terminator(*buffer)) {
            ++buffer;
        } else {
            int word_len = get_word_len(buffer);
            char *word = extract_word(buffer, word_len);
            to_lowercase(word);
            insert_or_update_wc_node(&head, word);
            free(word);
            buffer += word_len;
        }
    }

    return head;
}