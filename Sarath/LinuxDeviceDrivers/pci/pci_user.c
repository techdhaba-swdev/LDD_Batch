#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include<stdint.h>
#define DEVICE_NAME "/dev/intel_i3"

int main() {
    int fd;
    uint32_t value;

    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return errno;
    }

    printf("Reading from the device...\n");
    if (read(fd, &value, sizeof(value)) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return errno;
    }
    printf("Read from the device: 0x%X\n", value);

    value = 0xDEADBEEF;
    printf("Writing to the device: 0x%X\n", value);
    if (write(fd, &value, sizeof(value)) < 0) {
        perror("Failed to write to the device");
        close(fd);
        return errno;
    }

    close(fd);
    return 0;
}
