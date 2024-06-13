#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE "/dev/reverse_string"
#define BUFFER_SIZE 256

int main() {
    int fd;
    char write_buffer[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];
    ssize_t bytes_written, bytes_read;

    // Open the device file
    fd = open(DEVICE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Get input from the user
    printf("Enter a string to reverse: ");
    fgets(write_buffer, BUFFER_SIZE, stdin);
    write_buffer[strcspn(write_buffer, "\n")] = 0; // Remove the newline character

    // Write the data to the device
    bytes_written = write(fd, write_buffer, strlen(write_buffer));
    if (bytes_written < 0) {
        perror("Failed to write to the device");
        close(fd);
        return EXIT_FAILURE;
    }

    // Read the reversed data from the device
    bytes_read = read(fd, read_buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }

    // Null-terminate the read buffer and print the reversed string
    read_buffer[bytes_read] = '\0';
    printf("Reversed string: %s\n", read_buffer);

    // Close the device file
    close(fd);
    return EXIT_SUCCESS;
}
