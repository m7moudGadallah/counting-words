#include "input_handling.h"

#define BUFFER_CHUNK_SIZE 1024

ReadBuffer *create_read_buffer() {
    ReadBuffer *buffer = (ReadBuffer *)malloc(sizeof(ReadBuffer));
    if (!buffer) {
        perror("Error allocating ReadBuffer");
        return NULL;
    }

    buffer->data = (char *)malloc(BUFFER_CHUNK_SIZE);
    if (!buffer->data) {
        perror("Error allocating buffer data");
        free(buffer);
        return NULL;
    }

    buffer->size = 0;
    buffer->capacity = BUFFER_CHUNK_SIZE;
    buffer->data[0] = '\0'; // Initialize with null terminator
    return buffer;
}

void free_read_buffer(ReadBuffer *buffer) {
    if (buffer == NULL)
        return;
    free(buffer->data);
    free(buffer);
}

int append_to_buffer(ReadBuffer *buffer, char c) {
    if (buffer->size + 1 >= buffer->capacity) {
        buffer->capacity *= 2;
        char *new_data = (char *)realloc(buffer->data, buffer->capacity);
        if (!new_data) {
            perror("Error reallocating buffer data");
            return -1;
        }
        buffer->data = new_data;
    }

    buffer->data[buffer->size++] = c;
    buffer->data[buffer->size] = '\0'; // Null-terminate after appending
    return 0;
}

ReadBuffer *read_from_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    ReadBuffer *buffer = create_read_buffer();

    if (!buffer) {
        fclose(file);
        return NULL;
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        if (append_to_buffer(buffer, c) != 0) {
            free(buffer->data);
            free(buffer);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);
    return buffer;
}

ReadBuffer *read_from_stdin() {
    ReadBuffer *buffer = create_read_buffer();
    if (!buffer) {
        return NULL;
    }

    char c;
    while ((c = getchar()) != EOF) {
        if (append_to_buffer(buffer, c) != 0) {
            free(buffer->data);
            free(buffer);
            return NULL;
        }
    }

    return buffer;
}