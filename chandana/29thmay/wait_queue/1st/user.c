#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/mychardev"

int main()
{
    int fd;
    char buffer[256];
    ssize_t bytes_read;

    // Open the device
    fd = open(DEVICE_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Read from the device
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }

    // Null-terminate the buffer
    buffer[bytes_read] = '\0';

    // Print the data read from the device
    printf("Read from device: %s\n", buffer);

    // Close the device
    close(fd);

    return EXIT_SUCCESS;
}
