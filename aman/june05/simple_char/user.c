#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEVICE_NAME "/dev/simple_char_device"
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int fd;
    char read_buffer[BUFFER_SIZE];
    char write_buffer[] = "Hello, this is a test string for the character device driver.";
    ssize_t bytes_written, bytes_read;

    // Open the device 
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        handle_error("Failed to open the device");
    }

    // Write to the device 
    bytes_written = write(fd, write_buffer, strlen(write_buffer));
    if (bytes_written < 0) {
        handle_error("Failed to write to the device");
    }
    printf("Wrote %zd bytes to the device: %s\n", bytes_written, write_buffer);

    // Seek to the beginning of the device 
    if (lseek(fd, 0, SEEK_SET) < 0) {
        handle_error("Failed to seek to the beginning of the device");
    }

    // Read from the device 
    bytes_read = read(fd, read_buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        handle_error("Failed to read from the device");
    }
    read_buffer[bytes_read] = '\0';  // Null-terminate the string
    printf("Read %zd bytes from the device: %s\n", bytes_read, read_buffer);

    // Close the device 
    if (close(fd) < 0) {
        handle_error("Failed to close the device");
    }

    return 0;
}
