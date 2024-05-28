#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

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
    // Write some data to the file
    //const char *data_to_write = "Hello, World!\nThis is a test file.\n";
    // Read line by line from the file
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        // Null-terminate the buffer to treat it as a string
        buffer[bytes_read] = '\0';
        
        // Print the line
        printf("%s", buffer);
    }

    if (bytes_read == -1) {
        perror("Failed to read from file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("\nEnd of file reached.\n");

    // Close the file
    if (close(fd) == -1) {
        perror("Failed to close the file");
        exit(EXIT_FAILURE);
    }

    return 0;
}
