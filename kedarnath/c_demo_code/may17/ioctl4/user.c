#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/calculator_device"
#define IOCTL_MAGIC 'k'
#define IOCTL_CALCULATE _IOWR(IOCTL_MAGIC, 1, struct calc_data)

struct calc_data {
    int operand1;
    int operand2;
    char operator;
    int result;
};

int main() {
    int fd;
    struct calc_data data;

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    printf("Enter first operand: ");
    scanf("%d", &data.operand1);
    printf("Enter second operand: ");
    scanf("%d", &data.operand2);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &data.operator);

    if (ioctl(fd, IOCTL_CALCULATE, &data) < 0) {
        perror("Failed to execute ioctl");
        close(fd);
        return EXIT_FAILURE;
    }

    if (data.result == -1) {
        printf("Error: Division by zero\n");
    } else {
        printf("Result: %d\n", data.result);
    }

    close(fd);
    return EXIT_SUCCESS;
}



