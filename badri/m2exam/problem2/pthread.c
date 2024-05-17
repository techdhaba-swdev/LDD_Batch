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

// Function for writing lines to files
void *write_lines(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    while (1) {
        // Lock mutex to ensure exclusive access to input file
        pthread_mutex_lock(data->mutex);
        // Read a line from the input file
        if (fgets(line, sizeof(line), data->input_file) == NULL) {
            // Unlock mutex and break if end of file is reached
            pthread_mutex_unlock(data->mutex);
            break;
        }
        line_number++;
        // Debug statement to check the current line number and content
        printf("Read line %d: %s", line_number, line);
        // Check if the line number matches the thread's responsibility (even/odd)
        if ((line_number % 2 == 0 && data->line_type == 0) ||
            (line_number % 2 == 1 && data->line_type == 1)) {
            // Write the line to the appropriate output file
            fputs(line, data->output_file);
            // Debug statement to confirm the line was written
            printf("Written to %s file: %s", data->line_type == 0 ? "even" : "odd", line);
        }
        // Unlock mutex after processing the line
        pthread_mutex_unlock(data->mutex);
    }
    return NULL;
}


// Function for reading lines from files and printing them
void *read_and_print(void *arg) {
    FILE *file = (FILE *)arg;
    char line[MAX_LINE_LENGTH];

    // Read and print each line from the file
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    return NULL;
}


   
