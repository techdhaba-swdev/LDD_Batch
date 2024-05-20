#ifndef TASK2_H
#define TASK2_H

#include <pthread.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    const char *input_file;
    const char *output_file;
    int is_even;
} thread_data_t;

// Declare the mutex as extern
extern pthread_mutex_t file_mutex;

void* write_lines(void* arg);
void* read_lines(void* arg);

#endif // TASK2_H
