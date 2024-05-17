#ifndef FILE_H
#define FILE_H
#include <stdio.h>      // Standard input-output library
#include <stdlib.h>     // Standard library
#include <pthread.h>    // POSIX threads library



// Struct for passing arguments to threads
typedef struct {
      FILE *input_file;       // input file pointer
       FILE *output_file;      // output file pointer
     pthread_mutex_t *mutex; // mutex for locking 
 } ThreadArgs;



// Function declarations
void *even_lines(void *args); // Function to print even lines
void *odd_lines(void *args);  // Function to print  odd lines
void *read_and_print(void *filename); // Function to read and print file content


#endif
