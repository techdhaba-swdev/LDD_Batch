#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/calculator"

int main() {
    int fd;
    char operand[80];

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return -1;
    }

    // Prompt for input
    printf("Enter operand and operation (+, -, *, /) separated by space: ");
    fgets(operand, sizeof(operand), stdin);

    // Write input to device
    if (write(fd, operand, sizeof(operand)) < 0) {
        perror("Failed to write to the device");
        close(fd);
        return -1;
    }

    // Read result from device
    char result[80];
    if (read(fd, result, sizeof(result)) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return -1;
    }

    // Print the result
    printf("Result: %s\n", result);

    // Close the device file
    close(fd);

    return 0;
}
