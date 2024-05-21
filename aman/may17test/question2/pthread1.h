#ifndef PTHREAD1_H
#define PTHREAD1_H

#include <pthread.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

#define INPUT_FILE_NAME "test.txt"
#define EVEN_OUTPUT_FILE_NAME "even.txt"
#define ODD_OUTPUT_FILE_NAME "odd.txt"

typedef struct {
    char lines[MAX_LINES][MAX_LENGTH];
    int count;
    pthread_mutex_t mutex;
} LineBuffer;

void* readLines(void* arg);
void* writeLines(void* arg);
#endif 
