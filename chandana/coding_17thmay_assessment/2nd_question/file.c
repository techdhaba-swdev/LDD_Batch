#include "file.h" // Include the header file for function declarations



void *even_lines(void *args) {
    ThreadArgs *thread_args = (ThreadArgs *)args; // arguments to ThreadArgs struct
    char buffer[256]; // Buffer to store line content
    int line_number = 0; // Line number counter




while (fgets(buffer, sizeof(buffer), thread_args->input_file) != NULL) { // Read each line from input file
        line_number++; // Increment line number
        if (line_number % 2 == 0) { // Check if line number is even
            pthread_mutex_lock(thread_args->mutex); // Lock mutex for 
            fprintf(thread_args->output_file, "%s", buffer); // Write line to output file
            pthread_mutex_unlock(thread_args->mutex); // Unlock mutex
        }
    }

    pthread_exit(NULL); // Exit the thread
}





void *odd_lines(void *args) {
    ThreadArgs *thread_args = (ThreadArgs *)args; // arguments to ThreadArgs struct
    char buffer[256]; // Buffer to store line content
    int line_number = 0; // Line number counter

    

    
while (fgets(buffer, sizeof(buffer), thread_args->input_file) != NULL) { // Read each line from input file
        line_number++; // Increment line number
        if (line_number % 2 != 0) { // Check if line number is odd
            pthread_mutex_lock(thread_args->mutex); // Lock mutex for synchronization
            fprintf(thread_args->output_file, "%s", buffer); // Write line to output file
            pthread_mutex_unlock(thread_args->mutex); // Unlock mutex
        }
    }

    pthread_exit(NULL); // Exit the thread
}





void *read_and_print(void *filename) {
    char *file = (char *)filename; // filename to a char pointer
    FILE *output_file = fopen(file, "r"); // output file to read
    char buffer[256]; // Buffer to store line content



    if (output_file == NULL) { // Check if file opening fail
        perror("Error opening file"); // Print an error message
        exit(EXIT_FAILURE); // Exit the program with failure status
    }

    while (fgets(buffer, sizeof(buffer), output_file) != NULL) { // Read each line from output file
        printf("%s", buffer); // Print the line to console
    }




    fclose(output_file); // Close the output file
    pthread_exit(NULL); // Exit the thread
}
