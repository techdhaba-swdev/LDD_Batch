#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "file.h" // Include the header file containing function declarations

#define MAX_LINE_LENGTH 256






// Global variables
char input_filename[] = "input.txt";
char even_output_filename[] = "even_output.txt";
char odd_output_filename[] = "odd_output.txt";
pthread_mutex_t mutex;




// Function prototypes
void process_line(char* line, FILE* even_output_file, FILE* odd_output_file);
void write_to_file(char* line, FILE* output_file);
void read_from_file(char* filename);

// Function for processing even lines
void* process_even_lines(void* arg) {
FILE* input_file = fopen(input_filename, "r");
FILE* even_output_file = fopen(even_output_filename, "w");

 char line[MAX_LINE_LENGTH];
  int line_number = 1;

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        if (line_number % 2 == 0) {
            process_line(line, even_output_file, NULL); // Process even line
        }
        line_number++;
    }

    fclose(input_file);
    fclose(even_output_file);
    return NULL;
}






// Function for processing odd lines
void* process_odd_lines(void* arg) {
    FILE* input_file = fopen(input_filename, "r");
    FILE* odd_output_file = fopen(odd_output_filename, "w");

    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        if (line_number % 2 != 0) {
            process_line(line, NULL, odd_output_file); // Process odd line
        }
        line_number++;
    }

    fclose(input_file);
    fclose(odd_output_file);
    return NULL;
}




// Function to process a line and write it to the appropriate output file
void process_line(char* line, FILE* even_output_file, FILE* odd_output_file) {
    pthread_mutex_lock(&mutex);
    if (even_output_file) {
        write_to_file(line, even_output_file); // Write even line to file
    }
    if (odd_output_file) {
        write_to_file(line, odd_output_file); // Write odd line to file
    }
    pthread_mutex_unlock(&mutex);
}






// Function to write a line to a file
void write_to_file(char* line, FILE* output_file) {
    fprintf(output_file, "%s", line);
}





// Function to read and print content of a file
void* read_even_output(void* arg) {
    read_from_file(even_output_filename); // Read and print content of even output file
    return NULL;
}





// Function to read and print content of a file
void* read_odd_output(void* arg) {
    read_from_file(odd_output_filename); // Read and print content of odd output file
    return NULL;
}





// Function to read and print content of a file
void read_from_file(char* filename) {
    FILE* file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}
