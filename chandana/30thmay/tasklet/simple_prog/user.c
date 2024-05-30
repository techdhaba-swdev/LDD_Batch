#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/simple_char_dev"

int main() {
    int fd;

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    printf("Device opened successfully\n");

    // Close the device
    if (close(fd) < 0) {
        perror("Failed to close the device");
        return EXIT_FAILURE;
    }

    printf("Device closed successfully\n");
    return EXIT_SUCCESS;
}
