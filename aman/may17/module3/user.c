#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/calculator"
#define CALC_IOC_MAGIC 'k'
#define CALC_IOC_OPER _IOWR(CALC_IOC_MAGIC, 1, struct calc_data)

struct calc_data {
    int num1;
    int num2;
    char operation[10];
    int result;
};

int main() {
    int fd;
    struct calc_data data;
    char operation[10];

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd == -1) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Get user input
    printf("Enter first number: ");
    scanf("%d", &data.num1);
    printf("Enter second number: ");
    scanf("%d", &data.num2);
    printf("Enter operation (add, sub, mul, div): ");
    scanf("%s", operation);
    strncpy(data.operation, operation, sizeof(data.operation));

    // Send data to kernel and receive result
    if (ioctl(fd, CALC_IOC_OPER, &data) == -1) {
        perror("Failed to perform operation");
        close(fd);
        return EXIT_FAILURE;
    }

    // Print the result
    printf("Result: %d\n", data.result);

    // Close the device
    close(fd);
    return EXIT_SUCCESS;
}
