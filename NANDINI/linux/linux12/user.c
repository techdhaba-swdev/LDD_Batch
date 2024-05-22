#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/calculator_dev"

int main() {
    int fd;
    char operation;
    int operand1, operand2;

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
    printf("Enter two operands: ");
    scanf("%d %d", &operand1, &operand2);

    dprintf(fd, "%c %d %d", operation, operand1, operand2);

    char result[256];
    int bytes_read = read(fd, result, sizeof(result));
    if (bytes_read < 0) {
        perror("Failed to read from device");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Result: %s", result);

    close(fd);
    return EXIT_SUCCESS;
}
