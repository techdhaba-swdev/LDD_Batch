#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#define DEVICE_NAME "/dev/simple_chars_driver"
#define IOCTL_SET_MSG _IOW('q', 1, char *)

int main() {
    int fd;
    char message[100] = "New message for the driver";

    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    ioctl(fd, IOCTL_SET_MSG, message);

    close(fd);
return 0;
}
