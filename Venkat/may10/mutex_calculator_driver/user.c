#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define DEVICE_PATH "/dev/mutex_arithmetic"

int main() {
    int fd;
    int input_value1, input_value2, result;
    char operation;
    char buffer[2 * sizeof(int) + sizeof(char)]; // Buffer to hold both integers and the operation

    // Prompt the user for two integer values and an operation
    printf("Enter the first integer value: ");
    scanf("%d", &input_value1);
    printf("Enter the second integer value: ");
    scanf("%d", &input_value2);
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation); // Note the space before %c to consume any newline characters

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Prepare the buffer with the two input values and the operation
    memcpy(buffer, &input_value1, sizeof(int));
    memcpy(buffer + sizeof(int), &input_value2, sizeof(int));
    memcpy(buffer + 2 * sizeof(int), &operation, sizeof(char));

    // Write the buffer to the device
    if (write(fd, buffer, sizeof(buffer)) < 0) {
        perror("Failed to write to the device");
        close(fd);
        return 1;
    }

    // Read the result from the device
    if (read(fd, &result, sizeof(int)) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return 1;
    }

    printf("Result received from kernel: %d\n", result);

    // Close the device file
    close(fd);

    return 0;
}
