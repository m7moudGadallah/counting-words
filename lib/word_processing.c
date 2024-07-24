#include "word_processing.h"

bool is_word_terminator(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == '\0' || c == ',' ||
           c == '!' || c == '?';
}

int get_word_len(const char *buffer) {
    int len = 0;

    while (buffer != NULL && !is_word_terminator(*buffer)) {
        ++len;
        ++buffer;
    }

    return len;
}

char *extract_word(const char *buffer, int word_len) {
    char *word = (char *)malloc(sizeof(char) * word_len + 1);
    if (word == NULL) {
        perror("Error allocating space for word extraction!");
        return NULL;
    }

    int idx = 0;

    while (*buffer && idx < word_len) {
        word[idx] = *buffer;
        ++buffer;
        ++idx;
    }

    word[idx] = '\0';
    return word;
}

void to_lowercase(char *word) {
    while (*word) {
        if (*word >= 'A' && *word <= 'Z') {
            *word = *word + ('a' - 'A');
        }
        ++word;
    }
}