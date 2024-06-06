#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/kisssimplechardev" 
#define BUFFER_SIZE 1024

int main() {
    int fd;
    char write_buffer[] = "Hello, Simple Kernel!";
    char read_buffer[BUFFER_SIZE];

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Write to the device
    ssize_t bytes_written = write(fd, write_buffer, strlen(write_buffer));
    if (bytes_written < 0) {
        perror("Failed to write to the device");
        close(fd);
        return EXIT_FAILURE;
    }
    printf("Written to device: %s\n", write_buffer);

    // Read from the device
    ssize_t bytes_read = read(fd, read_buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }
    read_buffer[bytes_read] = '\0'; // Null-terminate the read buffer
    printf("Read from device: %s\n", read_buffer);

    // Close the device
    if (close(fd) < 0) {
        perror("Failed to close the device");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}




