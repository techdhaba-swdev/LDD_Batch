#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/my_ioctls_device"
#define IOCTL_MAGIC 'k'
#define IOCTL_ADD _IOWR(IOCTL_MAGIC, 1, int[3])
#define IOCTL_SUB _IOWR(IOCTL_MAGIC, 2, int[3])
#define IOCTL_MUL _IOWR(IOCTL_MAGIC, 3, int[3])
#define IOCTL_DIV _IOWR(IOCTL_MAGIC, 4, int[3])

void perform_operation(int fd, unsigned long cmd, int operand1, int operand2) {
    int values[3] = {operand1, operand2, 0};

    if (ioctl(fd, cmd, &values) < 0) {
        perror("Failed to execute ioctl");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Result: %d\n", values[2]);
}

int main() {
    int fd;
    int operand1, operand2;
    char operation;

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    printf("Enter operation (a: add, s: subtract, m: multiply, d: divide): ");
    scanf(" %c", &operation);
    printf("Enter operand1: ");
    scanf("%d", &operand1);
    printf("Enter operand2: ");
    scanf("%d", &operand2);

    switch (operation) {
        case 'a':
            perform_operation(fd, IOCTL_ADD, operand1, operand2);
            break;
        case 's':
            perform_operation(fd, IOCTL_SUB, operand1, operand2);
            break;
        case 'm':
            perform_operation(fd, IOCTL_MUL, operand1, operand2);
            break;
        case 'd':
            perform_operation(fd, IOCTL_DIV, operand1, operand2);
            break;
        default:
            printf("Invalid operation\n");
            break;
    }

    close(fd);
    return EXIT_SUCCESS;
}
