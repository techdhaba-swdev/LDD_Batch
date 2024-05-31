#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/usb_example"

int main() {
    int fd;
    char write_buf[] = "Hello USB!";
    char read_buf[512];
    int bytes_read, bytes_written;

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    printf("Device opened successfully\n");

    // Write to the device
    bytes_written = write(fd, write_buf, strlen(write_buf));
    if (bytes_written < 0) {
        perror("Failed to write to the device");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Wrote '%s' to the device\n", write_buf);

    // Read from the device
    bytes_read = read(fd, read_buf, sizeof(read_buf));
    if (bytes_read < 0) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }

    read_buf[bytes_read] = '\0'; // Null-terminate the read buffer
    printf("Read from the device: '%s'\n", read_buf);

    // Close the device
    if (close(fd) < 0) {
        perror("Failed to close the device");
        return EXIT_FAILURE;
    }

    printf("Device closed successfully\n");
    return EXIT_SUCCESS;
}
