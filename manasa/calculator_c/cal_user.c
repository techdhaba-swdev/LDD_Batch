#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/calculator"
#define BUFFER_SIZE 256

int main() {
    int fd;
    char input[BUFFER_SIZE];
    char result[BUFFER_SIZE];

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return -1;
    }

    // Prompt user for input
    printf("Enter arithmetic expression (e.g., '5 + 3'): ");
    fgets(input, sizeof(input), stdin);

    // Write input to the device file
    if (write(fd, input, sizeof(input)) < 0) {
        perror("Failed to write to the device file");
        close(fd);
        return -1;
    }

    // Read the result from the device file
    if (read(fd, result, sizeof(result)) < 0) {
        perror("Failed to read from the device file");
        close(fd);
        return -1;
    }

    // Display the result
    printf("Result: %s", result);

    // Close the device file
    close(fd);

    return 0;
}
