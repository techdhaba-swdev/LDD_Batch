#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_LENGTH 512
#define DEVICE_PATH "/dev/usb_example"

int main() {
    int fd;
    char buffer[BUFFER_LENGTH];
    int ret;

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return -1;
    }

    printf("Enter a message to send to the USB device: ");
    fgets(buffer, BUFFER_LENGTH, stdin);

    // Write to the device
    ret = write(fd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("Failed to write to the device");
        close(fd);
        return -1;
    }

    // Read from the device
    ret = read(fd, buffer, BUFFER_LENGTH);
    if (ret < 0) {
        perror("Failed to read from the device");
        close(fd);
        return -1;
    }

    printf("Message received from the USB device: %s\n", buffer);

    // Close the device file
    close(fd);

    return 0;
}
