#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/mycaldevice"
#define IOCTL_MAGIC 'c'
#define IOCTL_CALCULATE _IOWR(IOCTL_MAGIC, 1, struct operation_data)

struct operation_data {
    int num1;
    int num2;
    char operation;
    int result;
};

int perform_operation(int fd, struct operation_data *data) {
    if (ioctl(fd, IOCTL_CALCULATE, data) < 0) {
        perror("Failed to execute ioctl");
        return -1;
    }
    return 0;
}

void print_result(const char *operation_name, int result) {
    printf("%s Result: %d\n", operation_name, result);
}

int main() {
    int fd;
    struct operation_data data;

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Addition
    data.num1 = 10;
    data.num2 = 5;
    data.operation = '+';
    if (perform_operation(fd, &data) == 0) {
        print_result("Addition", data.result);
    }

    // Subtraction
    data.num1 = 20;
    data.num2 = 8;
    data.operation = '-';
    if (perform_operation(fd, &data) == 0) {
        print_result("Subtraction", data.result);
    }

    // Multiplication
    data.num1 = 7;
    data.num2 = 4;
    data.operation = '*';
    if (perform_operation(fd, &data) == 0) {
        print_result("Multiplication", data.result);
    }

    // Division
    data.num1 = 100;
    data.num2 = 5;
    data.operation = '/';
    if (perform_operation(fd, &data) == 0) {
        print_result("Division", data.result);
    }

    close(fd);
    return EXIT_SUCCESS;
}


