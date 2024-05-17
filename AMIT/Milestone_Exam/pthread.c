#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LINES 1000

                        // Global variables
FILE* input_file;           //input file that contain data
FILE* even_output_file;    //this file will only write even lines in the input file
FILE* odd_output_file;     //this file will write odd lines in input file
char lines[MAX_LINES][256]; // Assuming each line has a maximum length of 256 characters
int line_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* read_lines(void* arg) {                         
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), input_file)) //fgets read line from input file
    {
        pthread_mutex_lock(&mutex);              //protected by mutex lock
        strcpy(lines[line_count], buffer);     //copy the read lines in line array
        line_count++;                        //will increament the line count
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* write_even_lines(void* arg) {                  //this function will print even line from input file to even o/p file
    for (int i = 1; i < line_count; i += 2) {
        fprintf(even_output_file, "%s", lines[i]);
    }
    return NULL;
}

void* write_odd_lines(void* arg) {
    for (int i = 0; i < line_count; i += 2) {
        fprintf(odd_output_file, "%s", lines[i]);
    }
    return NULL;
}

int main() {
    input_file = fopen("input.txt", "r");
    even_output_file = fopen("even_output.txt", "w");
    odd_output_file = fopen("odd_output.txt", "w");

    if (!input_file || !even_output_file || !odd_output_file) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    pthread_t read_thread, even_thread, odd_thread;
    pthread_create(&read_thread, NULL, read_lines, NULL);
    pthread_create(&even_thread, NULL, write_even_lines, NULL);
    pthread_create(&odd_thread, NULL, write_odd_lines, NULL);

    pthread_join(read_thread, NULL);
    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);

    fclose(input_file);
    fclose(even_output_file);
    fclose(odd_output_file);

   

    return 0;
}
