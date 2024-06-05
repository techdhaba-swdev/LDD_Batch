#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/usb_example"

int main() {
    int fd;
    char read_buffer[256];
    char write_buffer[] = "Hello from user space!";

    // Open the USB device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Error opening device");
        return -1;
    }

    // Read data from the USB device
    ssize_t bytes_read = read(fd, read_buffer, sizeof(read_buffer));
    if (bytes_read > 0) {
        printf("Read from USB: %s\n", read_buffer);
    } else {
        perror("Error reading from device");
    }

    // Write data to the USB device
    ssize_t bytes_written = write(fd, write_buffer, strlen(write_buffer));
    if (bytes_written > 0) {
        printf("Wrote to USB: %s\n", write_buffer);
    } else {
        perror("Error writing to device");
    }

    // Close the device
    close(fd);

    return 0;
}


