#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/my_calculator_device"
#define IOCTL_MAGIC 'c'
#define IOCTL_CALC _IOWR(IOCTL_MAGIC, 1, struct calc_data)

struct calc_data {
    int num1;
    int num2;
    char operation; // '+', '-', '*', '/'
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

    printf("Enter first number: ");
    scanf("%d", &data.num1);
    printf("Enter second number: ");
    scanf("%d", &data.num2);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &data.operation); // Note the space before %c to consume any leftover newline

    if (ioctl(fd, IOCTL_CALC, &data) < 0) {
        perror("Failed to execute ioctl");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Result: %d %c %d = %d\n", data.num1, data.operation, data.num2, data.result);

    close(fd);
    return EXIT_SUCCESS;
}
