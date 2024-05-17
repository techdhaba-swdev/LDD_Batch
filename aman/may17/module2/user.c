#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_NAME "/dev/my_ioctl"
#define IOCTL_MAGIC 'k'
#define IOCTL_CMD _IOWR(IOCTL_MAGIC, 1, int)

int main() {
    int fd;
    int value;

    // Open the device
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Get user input
    printf("Enter an integer value: ");
    scanf("%d", &value);

    // Perform the IOCTL operation
    if (ioctl(fd, IOCTL_CMD, &value) < 0) {
        perror("Failed to perform IOCTL operation");
        close(fd);
        return EXIT_FAILURE;
    }

    // Output the modified value
    printf("Modified value from kernel: %d\n", value);

    // Close the device
    close(fd);

    return EXIT_SUCCESS;
}
