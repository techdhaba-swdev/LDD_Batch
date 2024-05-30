#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define DEVICE "/dev/char_device"
#define BUFFER_SIZE 1024

int main() {
    int fd;
    char write_buffer[BUFFER_SIZE] = "Hello, world!";
    char read_buffer[BUFFER_SIZE];

    // Open the device
    fd = open(DEVICE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device...");
        return errno;
    }

    // Write to the device
    printf("Writing to the device: %s\n", write_buffer);
    if (write(fd, write_buffer, strlen(write_buffer)) < 0) {
        perror("Failed to write to the device...");
        return errno;
    }

    // Read from the device
    printf("Reading from the device...\n");
    if (read(fd, read_buffer, BUFFER_SIZE) < 0) {
        perror("Failed to read from the device...");
        return errno;
    }
    printf("The received message is: %s\n", read_buffer);

    // Close the device
    close(fd);
    return 0;
}


