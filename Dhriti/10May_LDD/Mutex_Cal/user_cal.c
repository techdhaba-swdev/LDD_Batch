#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEV_NAME "/dev/calculator"

// IOCTL command to set operands
#define CALC_SET_OPERANDS _IOW('c', 1, int[2])

int main() {
    int fd;
    int operands[2];
    int result;

    // Open the device file
    fd = open(DEV_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device");
        return -1;
    }

    // Set operands
    operands[0] = 10;
    operands[1] = 5;
    if (ioctl(fd, CALC_SET_OPERANDS, operands) < 0) {
        perror("Failed to set operands");
        close(fd);
        return -1;
    }

    // Read result
    if (read(fd, &result, sizeof(result)) < 0) {
        perror("Failed to read result");
        close(fd);
        return -1;
    }

    // Print result
    printf("Result: %d\n", result);

    // Close device file
    close(fd);

    return 0;
}


