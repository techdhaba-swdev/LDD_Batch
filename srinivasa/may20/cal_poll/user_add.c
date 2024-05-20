#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <string.h>

#define DEVICE_PATH "/dev/calc_device"

void perform_addition(int num1, int num2) {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device");
        exit(EXIT_FAILURE);
    }

    char buffer[sizeof(int) * 2 + sizeof(char)];
    char operation = '+';
    memcpy(buffer, &num1, sizeof(int));
    memcpy(buffer + sizeof(int), &num2, sizeof(int));
    memcpy(buffer + sizeof(int) * 2, &operation, sizeof(char));

    if (write(fd, buffer, sizeof(buffer)) < 0) {
        perror("Failed to write to device");
        close(fd);
        exit(EXIT_FAILURE);
    }

    struct pollfd pfd = {fd, POLLIN, 0};
    poll(&pfd, 1, -1);

    int result;
    if (read(fd, &result, sizeof(result)) < 0) {
        perror("Failed to read from device");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Result of %d + %d = %d\n", num1, num2, result);
    close(fd);
}

int main() {
    int num1 = 5, num2 = 3;
    perform_addition(num1, num2);
    return 0;
}
