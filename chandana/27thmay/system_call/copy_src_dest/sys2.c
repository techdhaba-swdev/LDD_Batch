#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void copy(const char *source, const char *destination) {
    int src, dest;
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];

    // Open source file for reading
    src = open(source, O_RDONLY);
    if (src == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Open destination file for writing 
    if (dest == -1) {
        perror("Error opening destination file");
        close(src);
        exit(EXIT_FAILURE);
    }

    // Read from source and write to destination
    while ((bytes_read = read(src, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest, buffer, bytes_read) != bytes_read) {
            perror("Error writing to destination file");
            close(src);
            close(dest);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from source file");
    }

    // Close the files
    close(src);
    close(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    copy(argv[1], argv[2]);
    return 0;
}
