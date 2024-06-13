#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define IOCTL_SET_MSG _IOW('q', 1, char *)

int main() {
    int fd;
    char message[100] = "New message for the driver";
    char resultBuffer[100];
    fd = open("/dev/demo_char_driver", O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    ioctl(fd, IOCTL_SET_MSG, &message);

   read(fd,resultBuffer,100);
printf("%s",resultBuffer);
    close(fd);
    return 0;
}


