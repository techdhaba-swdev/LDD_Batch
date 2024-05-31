#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/mydevice"

int main() {
    int fd;
    char buf[1024];

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return errno;
    }

    // Read from the device
    printf("Reading from the device...\n");
    read(fd, buf, sizeof(buf));
    printf("Data read from the device: %s\n", buf);

    // Write to the device
    printf("Writing to the device...\n");
    char *data = "Hello, kernel!";
    write(fd, data, strlen(data));

    // Read again to see the updated data
    printf("Reading from the device again...\n");
    read(fd, buf, sizeof(buf));
    printf("Data read from the device: %s\n", buf);

    // Close the device file
    close(fd);
    return 0;
}
