#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/ioctl_dev"
#define IOCTL_MAGIC 'k'
#define IOCTL_MULTIPLY _IOW(IOCTL_MAGIC, 2, int)

int main() {
    int fd;
    int value = 42;

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    if (ioctl(fd, IOCTL_MULTIPLY, &value) < 0) {
        perror("Failed to execute ioctl");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Value multiplied by kernel: %d\n", value);

    close(fd);
    return EXIT_SUCCESS;
}



