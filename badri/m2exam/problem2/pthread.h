#ifndef PTHREAD_H
#define PTHREAD_H
#include "header.h"

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

char *lines[MAX_LINES];
int line_count = 0;

pthread_mutex_t file_mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    char *filename;
    int start_index;
    int step;
} thread_data_t;

void* write_lines(void* arg);
void* read_lines(void* arg);

#endif
