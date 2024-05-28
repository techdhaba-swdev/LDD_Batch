#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SOURCE_FILENAME "source.txt"
#define DEST_FILENAME "destination.txt"
#define BUFFER_SIZE 1024

int main() {
    int source_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    // Open the source file for reading
    source_fd = open(SOURCE_FILENAME, O_RDONLY);
    if (source_fd == -1) {
        perror("Failed to open source file for reading");
        exit(EXIT_FAILURE);
    }

    // Open or create the destination file for writing
    dest_fd = open(DEST_FILENAME, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (dest_fd == -1) {
        perror("Failed to open or create destination file for writing");
        close(source_fd);
        exit(EXIT_FAILURE);
    }

    // Read from the source file and write to the destination file
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Failed to write to destination file");
            close(source_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Failed to read from source file");
        close(source_fd);
        close(dest_fd);
        exit(EXIT_FAILURE);
    }

    printf("File copied successfully.\n");

    // Close the files
    if (close(source_fd) == -1) {
        perror("Failed to close source file");
        exit(EXIT_FAILURE);
    }
    if (close(dest_fd) == -1) {
        perror("Failed to close destination file");
        exit(EXIT_FAILURE);
    }

    return 0;
}
