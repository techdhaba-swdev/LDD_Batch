#include<string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


#define BUFFER_SIZE 256

int main() {
    int fd, num_bytes;
    char file_path[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    printf("Enter the file path: ");
    if (fgets(file_path, BUFFER_SIZE, stdin) == NULL) {
        perror("Error reading file path");
        exit(EXIT_FAILURE);
    }

    file_path[strcspn(file_path, "\n")] = '\0';

    fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((num_bytes = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, num_bytes) != num_bytes) {
            perror("Error writing to stdout");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    if (num_bytes == -1) {
        perror("Error reading file");
        close(fd);
        exit(EXIT_FAILURE);
    }

   
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    return 0;
}
