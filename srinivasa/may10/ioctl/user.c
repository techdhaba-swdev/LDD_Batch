#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

#define DEVICE_PATH "/dev/reverse"

#define IOCTL_REVERSE_STRING _IOWR('R', 1, char *)

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    int fd;
    char str[] = "Hello, world!";

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device.");
        return -1;
    }

    printf("Original string: %s\n", str);
    if (ioctl(fd, IOCTL_REVERSE_STRING, str) < 0) {
        perror("Failed to perform ioctl operation.");
        close(fd);
        return -1;
    }
    printf("Reversed string: %s\n", str);

    close(fd);
    return 0;
}
