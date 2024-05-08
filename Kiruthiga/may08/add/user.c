#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/add_two_numbers"

int main() {
    int fd;
    int num1, num2, result;

    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Write the two input values to the device
    write(fd, &num1, sizeof(int));
    write(fd, &num2, sizeof(int));

    // Read the result value from the device
    read(fd, &result, sizeof(int));

    printf("Result received from kernel: %d\n", result);

    // Close the device file
    close(fd);

    return 0;
}
