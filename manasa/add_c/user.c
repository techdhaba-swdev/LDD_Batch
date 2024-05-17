#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/add_values"

int main() {
    int fd;
    int value1, value2, result;

    printf("Enter two integer values: ");
    scanf("%d %d", &value1, &value2);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Prepare the buffer to hold both values
    int buffer[2] = {value1, value2};

    // Write both values to the device
    write(fd, buffer, 2 * sizeof(int));

    // Read the result from the device
    read(fd, &result, sizeof(int));

    printf("Result value received from kernel: %d\n", result);

    // Close the device file
    close(fd);

    return 0;
}
