#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/temperature_sensor"

int main() {
    int fd;
    int temp;

    fd = open(DEVICE_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open the device file");
        return -1;
    }

    if (read(fd, &temp, sizeof(temp)) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return -1;
    }

    printf("Temperature: %d\n", temp);

    close(fd);
    return 0;
}
