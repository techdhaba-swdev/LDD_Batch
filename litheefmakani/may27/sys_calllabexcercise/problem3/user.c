#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Read data from standard input until EOF (end-of-file)
    while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1)) > 0) {
        // Ensure null termination for safe printing
        buffer[bytes_read] = '\0';

        // Write the read data to standard output
        if (write(STDOUT_FILENO, buffer, bytes_read) == -1) {
            perror("Failed to write to standard output");
            exit(EXIT_FAILURE);
        }
    }

    // Check for errors during reading
    if (bytes_read == -1) {
        perror("Failed to read from standard input");
        exit(EXIT_FAILURE);
    }

    // No data read (EOF reached) or successful read without errors
    return 0;
}
