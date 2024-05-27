#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    char source_file[] = "badri.txt";
    char dest_file[] = "destination.txt";

    char buffer[BUFFER_SIZE];
    int source_fd, dest_fd;
    ssize_t bytes_read, bytes_written;

    // Open source file for reading
    source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        return 1;
    }

    // Open destination file for writing (create if it doesn't exist, truncate if it does)
    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(source_fd);
        return 1;
    }

    // Copy content from source file to destination file
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from source file");
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    // Close both files
    close(source_fd);
    close(dest_fd);

    printf("File copied successfully.\n");

    return 0;
}
