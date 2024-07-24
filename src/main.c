#include "../lib/input_handling.h"
#include "../lib/word_count.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");

    ReadBuffer *input_buffer = NULL;

    if (argc > 1) {
        input_buffer = read_from_file(argv[1]);
    } else {
        input_buffer = read_from_stdin();
    }

    // word counts
    printf("input: %s\n----\n", input_buffer->data);
    printf("count words: %d\n", count_words(input_buffer->data));

    // word frequency count
    WCNode *wc_list = count_word_frequencies(input_buffer->data, NULL);
    print_list(wc_list);
    printf("\n");

    // free input_buffer
    if (input_buffer)
        free_read_buffer(input_buffer);
    // free wc_list
    if (wc_list)
        free_list(wc_list);

    return 0;
}