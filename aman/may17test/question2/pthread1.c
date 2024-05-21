#include "pthread1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* readLines(void* arg) {
    FILE* file = fopen(INPUT_FILE_NAME, "r");
    char line[MAX_LENGTH];
    int lineNumber = 1;

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    LineBuffer* buffer = (LineBuffer*)arg;

    while (fgets(line, sizeof(line), file) != NULL) {
        pthread_mutex_lock(&buffer->mutex);
        if (lineNumber % 2 == 0) {
            strcpy(buffer->lines[buffer->count++], line);
        }
        pthread_mutex_unlock(&buffer->mutex);
        lineNumber++;
    }

    fclose(file);
    pthread_exit(NULL);
}

void* writeLines(void* arg) {
    LineBuffer* buffer = (LineBuffer*)arg;
    FILE* file;
    char* fileName;

    if (strcmp((char*)arg, "even") == 0) {
        fileName = EVEN_OUTPUT_FILE_NAME;
    } else {
        fileName = ODD_OUTPUT_FILE_NAME;
    }

    file = fopen(fileName, "w");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_lock(&buffer->mutex);
    for (int i = 0; i < buffer->count; i++) {
        fputs(buffer->lines[i], file);
    }
    pthread_mutex_unlock(&buffer->mutex);

    fclose(file);
    pthread_exit(NULL);
}

