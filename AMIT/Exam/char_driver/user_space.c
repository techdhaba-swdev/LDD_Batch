#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/virtual_temp"

int main() {
    int fd = open(DEVICE_PATH, O_RDONLY);
    if (fd == -1) {
        perror("Error opening device");
        return 1;
    }

    char buffer[10];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("Error reading from device");
        close(fd);
        return 1;
    }

    printf("Temperature: %s", buffer);

    close(fd);
    return 0;
}


