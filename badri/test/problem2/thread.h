#include<stdio.h>//includes standard input and output fucntions like scanf and printf
#include<stdlib.h>//includes libraries like malloc for memory allocation
#include<pthread.h>//includes attributes mutex to create pthreads


//function declarations
void *read_file(void *filename);//function to read a file
void *write_odd_lines(void *filename);//function to write oddlines to a file
void *write_even_lines(void *filename);//function to read evenlines to a file
#define MAX_LINE_LENGTH 1024//defines maximum line length
#define NUM_LINES 10//defines number of lines
