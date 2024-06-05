
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEVICE_PATH "/dev/usb"

int main() {
    int fd;
    char write_buf[512];
    char read_buf[512];
    ssize_t bytes_written, bytes_read;

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return errno;
    }

    // Write data to the device
    snprintf(write_buf, sizeof(write_buf), "Hello, USB device!");
    bytes_written = write(fd, write_buf, strlen(write_buf));
    if (bytes_written < 0) {
        perror("Failed to write to the device");
        close(fd);
        return errno;
    }

    printf("Wrote %zd bytes to the device: %s\n", bytes_written, write_buf);

    // Read data from the device
    bytes_read = read(fd, read_buf, sizeof(read_buf));
    if (bytes_read < 0) {
        perror("Failed to read from the device");
        close(fd);
        return errno;
    }

    read_buf[bytes_read] = '\0';  // Null-terminate the read buffer
    printf("Read %zd bytes from the device: %s\n", bytes_read, read_buf);

    // Close the device file
    close(fd);

    return 0;
}
