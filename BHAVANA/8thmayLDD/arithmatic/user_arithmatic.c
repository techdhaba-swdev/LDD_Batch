#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>

#define DEVICE_NAME "/dev/arithmetic_operations"

#define CMD_SUM         0
#define CMD_SUBTRACTION 1
#define CMD_MULTIPLY    2
#define CMD_DIVISION    3

int main() {
    int fd;
    char buf[100];
    int operand1, operand2;
    int result;

    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return errno;
    }

    printf("Enter two integers: ");
    scanf("%d %d", &operand1, &operand2);
    snprintf(buf, sizeof(buf), "%d %d", operand1, operand2);
    write(fd, buf, sizeof(buf));

    printf("Choose operation:\n");
    printf("0: Sum\n");
    printf("1: Subtraction\n");
    printf("2: Multiplication\n");
    printf("3: Division\n");
    int cmd;
    scanf("%d", &cmd);

    if (ioctl(fd, cmd, 0) < 0) {
        perror("ioctl failed");
        close(fd);
        return errno;
    }

    read(fd, &result, sizeof(int));
    printf("Result read from kernel: %d\n", result);

    close(fd);
    return 0;
}
