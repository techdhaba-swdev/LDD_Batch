#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FILENAME "exampleread.txt"
#define BUFFER_SIZE 1024

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

     fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file for reading");
        exit(EXIT_FAILURE);
    }

    
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE))>0){
	      	    ssize_t i;
        for (i = 0; i < bytes_read; i++) {
            putchar(buffer[i]);
            if (buffer[i] == '\n') {
                putchar('\n'); // Print newline character for line break
            }
        }
    }

    // Check for read error
    if (bytes_read == -1) {
        perror("Error reading from file");
    } else {
        printf("End of file reached.\n");
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Failed to close the file after reading");
        exit(EXIT_FAILURE);
    }

    return 0;
}
