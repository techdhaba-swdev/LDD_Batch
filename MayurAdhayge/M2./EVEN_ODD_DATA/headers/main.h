#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *readFile(void *filename);
void *writeOddLines(void *filename);
void *writeEvenLines(void *filename);
#define MAX_LINE_LENGTH 1024
#define NUM_LINES 10

#endif 

