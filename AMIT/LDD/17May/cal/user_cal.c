#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/calculator_ioctl"
#define IOCTL_MAGIC 'k'
#define IOCTL_CALCULATE _IOWR(IOCTL_MAGIC, 1, struct calc_request)

struct calc_request {
    int num1;
    int num2;
    char operation; // 'a' for add, 's' for subtract, 'm' for multiply, 'd' for divide
    int result;
};

int main() {
    int fd;
    struct calc_request request;

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Get input from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &request.num1, &request.num2);

    printf("Enter operation (a for add, s for subtract, m for multiply, d for divide): ");
    scanf(" %c", &request.operation);

    // Send the request to the kernel
    if (ioctl(fd, IOCTL_CALCULATE, &request) < 0) {
        perror("Failed to execute ioctl");
        close(fd);
        return EXIT_FAILURE;
    }

    // Print the result received from the kernel
    printf("Result: %d\n", request.result);

    close(fd);
    return EXIT_SUCCESS;
}
