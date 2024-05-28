#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/char_dev"
#define BUF_SIZE 1024

int main() {
    int fd;
    char buffer[BUF_SIZE];
    ssize_t bytes_read, bytes_written;

    // Open the character device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd == -1) {
        perror("Error opening device");
        return 1;
    }

    // Write data to the device
    const char* data_to_write = "Hello, Kernel!";
    bytes_written = write(fd, data_to_write, strlen(data_to_write));
    if (bytes_written == -1) {
        perror("Error writing to device");
        close(fd);
        return 1;
    }
    printf("Data written to device: %s\n", data_to_write);

    // Read data from the device
    bytes_read = read(fd, buffer, BUF_SIZE);
    if (bytes_read == -1) {
        perror("Error reading from device");
        close(fd);
        return 1;
    }
    buffer[bytes_read] = '\0'; // Null-terminate the string
    printf("Data read from device: %s\n", buffer);

    // Close the device
    close(fd);

    return 0;
}
