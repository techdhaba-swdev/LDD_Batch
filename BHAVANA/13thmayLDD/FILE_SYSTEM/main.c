#include "file_system.h" // Including the header file for file system notifier functions
#include <stdio.h> // Including standard input/output functions
#include <stdlib.h> // Including standard library functions

int main(int argc, char **argv) { // Main function definition with command-line arguments
    if (argc < 2) { // Checking if there are fewer than two command-line arguments
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]); // Printing usage message to standard error
        exit(EXIT_FAILURE); // Exiting the program with failure status
    }

    if (init_fs_notifier(argv[1]) != 0) { // Calling function to initialize file system notifier with directory argument
        fprintf(stderr, "Failed to initialize file system notifier\n"); // Printing error message if initialization fails
        exit(EXIT_FAILURE); // Exiting the program with failure status
    }

    start_fs_monitoring(); // Calling function to start monitoring the file system

    stop_fs_monitoring(); // Calling function to stop monitoring the file system
    return 0; // Exiting the program with success status
}
