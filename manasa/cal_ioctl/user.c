#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/calculator_dev"

#define CALCULATOR_IOC_MAGIC 'k'
#define CALCULATOR_IOC_SET_OPERATION _IOW(CALCULATOR_IOC_MAGIC, 1, char)
#define CALCULATOR_IOC_SET_OPERANDS _IOW(CALCULATOR_IOC_MAGIC, 2, int[2])
#define CALCULATOR_IOC_GET_RESULT _IOR(CALCULATOR_IOC_MAGIC, 3, int)

int main() {
    int fd;
    char operation;
    int operands[2];
    int result;

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Set operation
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
    if (ioctl(fd, CALCULATOR_IOC_SET_OPERATION, &operation) < 0) {
        perror("Failed to set operation");
        close(fd);
        return EXIT_FAILURE;
    }

    // Set operands
    printf("Enter two operands: ");
    scanf("%d %d", &operands[0], &operands[1]);
    if (ioctl(fd, CALCULATOR_IOC_SET_OPERANDS, &operands) < 0) {
        perror("Failed to set operands");
        close(fd);
        return EXIT_FAILURE;
    }

    // Get result
    if (ioctl(fd, CALCULATOR_IOC_GET_RESULT, &result) < 0) {
        perror("Failed to get result");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Result: %d\n", result);

    close(fd);
    return EXIT_SUCCESS;
}
