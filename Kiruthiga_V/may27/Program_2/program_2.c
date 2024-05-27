#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FILENAME "example.txt"
#define BUFFER_SIZE 1024

int main() {
    int fd;
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];

    // Open the file for reading
    fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file for reading");
        exit(EXIT_FAILURE);
    }

    // Read the data from the file line by line
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer

        // Print each line as it is read
        printf("%s", buffer);
    }

    if (bytes_read == -1) {
        perror("Failed to read from file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Failed to close the file after reading");
        exit(EXIT_FAILURE);
    }

    return 0;
}


