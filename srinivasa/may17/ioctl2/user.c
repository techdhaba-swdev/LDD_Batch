#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/my_ioctldevice"
#define IOCTL_MAGIC 'k'
#define IOCTL_CMD_WRITE _IOW(IOCTL_MAGIC, 1, int)
#define IOCTL_CMD_READ  _IOR(IOCTL_MAGIC, 1, int)

int main() {
    int fd;
    int value = 42;

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    if (ioctl(fd, IOCTL_CMD_WRITE, &value) < 0) {
        perror("Failed to execute ioctl");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("IOCTL command sent with value: %d\n", value);

    if (ioctl(fd, IOCTL_CMD_READ, &value) < 0) {
        perror("Failed to execute ioctl");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("IOCTL command recived with value: %d\n", value);


    close(fd);
    return EXIT_SUCCESS;
}
