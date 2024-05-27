#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void copy_file(const char *source, const char *destination) {
    int src_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    // Open the source file for reading
    src_fd = open(source, O_RDONLY);
    if (src_fd == -1) {
        perror("Failed to open source file for reading");
        exit(EXIT_FAILURE);
    }

    // Open the destination file for writing (create if it doesn't exist, truncate if it does)
    dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (dest_fd == -1) {
        perror("Failed to open destination file for writing");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    // Copy data from source to destination
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Failed to write data to destination file");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Failed to read data from source file");
    }

    // Close both files
    if (close(src_fd) == -1) {
        perror("Failed to close source file");
        exit(EXIT_FAILURE);
    }

    if (close(dest_fd) == -1) {
        perror("Failed to close destination file");
        exit(EXIT_FAILURE);
    }

    printf("File copied successfully from %s to %s\n", source, destination);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    copy_file(argv[1], argv[2]);

    return 0;
}


