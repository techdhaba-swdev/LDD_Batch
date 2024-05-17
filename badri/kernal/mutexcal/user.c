#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/swap_device"

int main() {
    int fd;
    char buffer[2 * sizeof(int)];
    int num1, num2;

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        printf("Failed to open the device file\n");
        return -1;
    }

    // Read the swapped numbers from the device file
    if (read(fd, buffer, 2 * sizeof(int)) < 0) {
        printf("Failed to read from the device file\n");
        close(fd);
        return -1;
    }

    // Extract the numbers from the buffer
    memcpy(&num1, buffer, sizeof(int));
    memcpy(&num2, buffer + sizeof(int), sizeof(int));

    // Print the swapped numbers
    printf("Swapped numbers: %d, %d\n", num1, num2);

    // Close the device file
    close(fd);

    return 0;
}
