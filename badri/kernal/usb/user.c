#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/usb_example"

int main() {
    int fd;
    char write_buf[512] = "Hello from user space!";
    char read_buf[512];
    ssize_t bytes_written, bytes_read;

    
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device...");
        return errno;
    }

    
    bytes_written = write(fd, write_buf, strlen(write_buf));
    if (bytes_written < 0) {
        perror("Failed to write the message to the device.");
        close(fd);
        return errno;
    }
    printf("Wrote %ld bytes to the device.\n", bytes_written);

    
    bytes_read = read(fd, read_buf, sizeof(read_buf));
    if (bytes_read < 0) {
        perror("Failed to read the message from the device.");
        close(fd);
        return errno;
    }
    printf("Read %ld bytes from the device: %s\n", bytes_read, read_buf);

    
    close(fd);

    return 0;
}
