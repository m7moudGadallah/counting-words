#include "../lib/input_handling.h"
#include "../lib/word_count.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void print_usage(const char *);
int compare_wc_nodes(WCNode *, WCNode *);

int main(int argc, char *argv[]) {
    bool count_flag = false;
    bool freq_flag = false;
    bool sort_flag = false;
    bool reverse_flag = false;
    char *file_path = NULL;

    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            for (int j = 1; argv[i][j] != '\0'; ++j) {
                switch (argv[i][j]) {
                case 'c':
                    count_flag = true;
                    break;
                case 'f':
                    freq_flag = true;
                    break;
                case 's':
                    sort_flag = true;
                    break;
                case 'r':
                    reverse_flag = true;
                    break;
                default:
                    print_usage(argv[0]);
                    return 1;
                }
            }
        } else {
            file_path = argv[i];
        }
    }

    // Default to both counting and frequency if no flags are provided
    if (!count_flag && !freq_flag) {
        count_flag = true;
        freq_flag = true;
    }

    ReadBuffer *input_buffer =
        (file_path != NULL) ? read_from_file(file_path) : read_from_stdin();

    // word counts
    if (count_flag) {
        printf("count words: %d\n", count_words(input_buffer->data));
    }

    // word frequency count
    if (freq_flag) {
        WCNode *wc_list = count_word_frequencies(input_buffer->data, NULL);

        if (sort_flag) {
            sort_wc_list(&wc_list, compare_wc_nodes);
        }

        print_list(wc_list, reverse_flag);
        printf("\n");

        if (wc_list)
            free_list(wc_list);
    }

    // free input_buffer
    if (input_buffer)
        free_read_buffer(input_buffer);

    return 0;
}

void print_usage(const char *prog_name) {
    printf("Usage: %s [OPTION] [FILE]\n", prog_name);
    printf("Options:\n");
    printf("  -c   Count words\n");
    printf("  -f   Count word frequencies\n");
    printf("  -s   Sort word frequencies\n");
    printf("  -r   Print word frequencies in reverse order\n");
    printf("  -cf  Count words and word frequencies (default)\n");
}

int compare_wc_nodes(WCNode *node1, WCNode *node2) {
    int comp = node2->count - node1->count;
    return (comp) ? comp
                  : strcmp(node1->word,
                           node2->word); // Sorting in descending order of count
}