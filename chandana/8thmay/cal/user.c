#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/cal_integer"

int main() {
    int fd;
    int input_values[3]; // First two integers are values, the third is the operation code
    int result;

    printf("Enter two integer values and an operation code (0:add, 1:subtract, 2:multiply, 3:divide): ");
    scanf("%d %d %d", &input_values[0], &input_values[1], &input_values[2]);

    // Combine the two integers and the operation code into a single integer
    int input_data = (input_values[0] << 16) | ((input_values[1] & 0xFFFF) << 8) | (input_values[2] & 0xFF);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Write the input values and operation code to the device
    write(fd, &input_data, sizeof(int));

    // Read the result from the device
    read(fd, &result, sizeof(int));

    printf("Result received from kernel: %d\n", result);

    // Close the device file
    close(fd);

    return 0;
}
