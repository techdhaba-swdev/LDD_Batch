#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NODE "/dev/usb_example" // Path to the device node

int main() {
    int fd;
    char buffer[512];
    ssize_t num_bytes;

    // Open the device node for reading and writing
    fd = open(DEVICE_NODE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device node");
        return EXIT_FAILURE;
    }

    // Write data to the device
    strcpy(buffer, "Hello from user space!");
    num_bytes = write(fd, buffer, strlen(buffer));
    if (num_bytes < 0) {
        perror("Failed to write to the device");
        close(fd);
        return EXIT_FAILURE;
    }

    // Read data from the device
    num_bytes = read(fd, buffer, sizeof(buffer));
    if (num_bytes < 0) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }

    // Display the read data
    printf("Received data from device: %s\n", buffer);

    // Close the device node
    close(fd);

    return EXIT_SUCCESS;
}
