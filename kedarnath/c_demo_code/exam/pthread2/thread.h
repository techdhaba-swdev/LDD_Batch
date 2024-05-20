#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *read_file(void *filename);
void *write_odd_lines(void *filename);
void *write_even_lines(void *filename);
#define MAX_LINE_LENGTH 1024
#define NUM_LINES 10


