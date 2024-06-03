#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NAME "/dev/simple_dma"
#define BUFFER_SIZE 4096  // Should match DMA_BUFFER_SIZE in the kernel module

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_written, bytes_read;

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Write some data to the device
    const char *data_to_write = "Hello from user space";
    bytes_written = write(fd, data_to_write, strlen(data_to_write));
    if (bytes_written < 0) {
        perror("Failed to write to the device");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Written %ld bytes to the device\n", bytes_written);

    // Read the data back from the device
    bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }

    // Null-terminate the read data
    buffer[bytes_read] = '\0';
    printf("Read %ld bytes from the device: %s\n", bytes_read, buffer);

    // Close the device file
    close(fd);

    return EXIT_SUCCESS;
}

