#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NODE "/dev/mychardev"
#define BUFFER_SIZE 256

int main() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Open the device node
    fd = open(DEVICE_NODE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device node");
        return -1;
    }

    // Read from the device
    printf("Reading from the device...\n");
    if (read(fd, buffer, BUFFER_SIZE) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return -1;
    }
    printf("Message from the device: %s", buffer);

    // Close the device node
    close(fd);

    return 0;
}


