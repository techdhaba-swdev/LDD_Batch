#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//  maximum length of a line 
#define MAX_LEN 250

// structure to pass data to threads
typedef struct {
    FILE *in_file;          
    FILE *output_files;         
    int start_line;            
    int line_step;             
    pthread_mutex_t *file_mutex; // pointer mutex  file access synchronization
} thread_data;

//  to be executed by writer threads
void *writing_line(void *arg) {
    thread_data *data = (thread_data *)arg; //  the argument to thread_data
    char line[MAX_LEN];                 // buffer to hold each line from the file
    int line_number = 1;                        // Line counter

    // Read lines from the input file
    while (fgets(line, MAX_LEN, data->in_file) != NULL) {
        pthread_mutex_lock(data->file_mutex);   
        // if the line number matches the required line type (even or odd)
        if ((line_number - data->start_line) % data->line_step == 0) {
            fputs(line, data->output_files);     // write the line to the output file
        }
        pthread_mutex_unlock(data->file_mutex); // Unlock the mutex
        line_number++;                          // increment the line counter
    }

    return NULL; 
}

// function to be executed by reader threads
void *read_print(void *arg) {
    FILE *file = (FILE *)arg;    // Cast the argument to a file pointer
    char line[MAX_LEN];  // bffer to hold each line from the file

    // Read and print lines from the output file
    while (fgets(line, MAX_LEN, file) != NULL) {
        printf("%s", line);      // line to the console
    }

    return NULL; // Thread function must return a void pointer
}

int main() {
    pthread_t write_thread1, write_thread2, read_thread1, read_thread2; // Thread identifiers
    FILE *in_file = fopen("input.txt", "r");     // Open the input file for reading
    FILE *even_file = fopen("even.txt", "w");       // Open the even output file for write
    FILE *odd_file = fopen("odd.txt", "w");         // odd output file for writing

    // if any file failed to open
    if (!in_file || !even_file || !odd_file) {
        perror("error opening file");               // error message
        return EXIT_FAILURE;                        // exit the program 
    }

    pthread_mutex_t file_mutex = PTHREAD_MUTEX_INITIALIZER; // initialize mutex

    // data for the even lines writer thread
    thread_data even_data = {in_file, even_file, 2, 2, &file_mutex};
    // Prepare data for the odd lines writer thread
    thread_data odd_data = {in_file, odd_file, 1, 2, &file_mutex};

    //the even lines writer thread
    pthread_create(&write_thread1, NULL, writing_line, &even_data);
    // the odd lines writer thread
    pthread_create(&write_thread2, NULL, writing_line, &odd_data);

    // even lines writer thread to finish 
    pthread_join(write_thread1, NULL);
    // wait  odd lines writer thread to finish
    pthread_join(write_thread2, NULL);

    fclose(in_file);  // close the input file
    fclose(even_file);   // close the even output file
    fclose(odd_file);    // close the odd output file

    
    even_file = fopen("even.txt", "r");
    // reopen the odd output file for reading
    odd_file = fopen("odd.txt", "r");

    // check if any output file failed to open
    if (!even_file || !odd_file) {
        perror("Error opening output file");        // print error message
        return EXIT_FAILURE;                        // exit the program with failure status
    }

    // the even lines reader thread
    pthread_create(&read_thread1, NULL, read_print, even_file);
    
    pthread_create(&read_thread2, NULL, read_print, odd_file);

    // Wait  even lines reader thread to finish
    pthread_join(read_thread1, NULL);
    // wait f odd lines reader thread to finish
    pthread_join(read_thread2, NULL);

    fclose(even_file); // close the even output file
    fclose(odd_file);  // close the odd output file

    return EXIT_SUCCESS; // exit the program with success status
}