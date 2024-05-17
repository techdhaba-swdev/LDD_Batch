#ifndef PTHREAD_H
#define PTHRERAD_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 1024

// Structure to pass information to threads
typedef struct {
    FILE *input_file;
    FILE *output_file;
    pthread_mutex_t *mutex;
    int line_type; // 0 for even lines, 1 for odd lines
} ThreadData;
void *write_lines(void *arg);
void *read_and_print(void *arg);

#endif
