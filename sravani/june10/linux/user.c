#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/temp_sensor"

int main() {
    int fd;
    char buf[10];
    ssize_t bytes_read;

    fd = open(DEVICE_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    bytes_read = read(fd, buf, sizeof(buf) - 1);
    if (bytes_read < 0) {
        perror("Failed to read the device");
        close(fd);
        return EXIT_FAILURE;
    }

    buf[bytes_read] = '\0';
    printf("Temperature: %s", buf);

    close(fd);
    return EXIT_SUCCESS;
}
	

