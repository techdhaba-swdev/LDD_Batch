#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/mychardev"
#define BUFFER_SIZE 256

int main() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Open the device file
    fd = open(DEVICE_FILE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return EXIT_FAILURE;
    }

    // Read data from the device file
    if (read(fd, buffer, BUFFER_SIZE) < 0) {
        perror("Failed to read from the device file");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Received message from kernel: %s\n", buffer);

    // Close the device file
    close(fd);

    return EXIT_SUCCESS;
}
