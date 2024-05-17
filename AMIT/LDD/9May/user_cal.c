#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/calculator"

int main() {
    int fd;
    int operand1, operand2, result;
    char operation;

    printf("Enter an expression (operand1 operation operand2): ");
    scanf("%d %c %d", &operand1, &operation, &operand2);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Write the expression to the device
    dprintf(fd, "%d %c %d", operand1, operation, operand2);

    // Read the result from the device
    read(fd, &result, sizeof(int));

    printf("Result received from kernel: %d\n", result);

    // Close the device file
    close(fd);

    return 0;
}
