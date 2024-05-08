#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/sum_integer_driver"

int main() {
    int fd;
    int input_value1, input_value2, sum;

    // Prompt the user for two integer values
    printf("Enter the first integer value: ");
    scanf("%d", &input_value1);
    printf("Enter the second integer value: ");
    scanf("%d", &input_value2);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Write the two input values to the device
    if (write(fd, &input_value1, sizeof(int)) < 0 || write(fd, &input_value2, sizeof(int)) < 0) {
        perror("Failed to write to the device");
        close(fd);
        return 1;
    }

    // Read the sum from the device
    if (read(fd, &sum, sizeof(int)) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return 1;
    }

    printf("Sum received from kernel: %d\n", sum);

    // Close the device file
    close(fd);

    return 0;
}
