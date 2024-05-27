#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/simple_char_device"
#define BUFFER_SIZE 256

int main() {
    int fd;
    char write_buf[BUFFER_SIZE];
    char read_buf[BUFFER_SIZE];
    ssize_t bytes_written, bytes_read;

    // Prompt the user for input
    printf("Enter a string to send to the device: ");
    scanf("%255s", write_buf); // Using %255s to prevent buffer overflow

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return 1;
    }

    // Write the string to the device
    bytes_written = write(fd, write_buf, strlen(write_buf));
    if (bytes_written < 0) {
        perror("Failed to write to the device");
        close(fd);
        return 1;
    }

    // Read back the data from the device
    bytes_read = read(fd, read_buf, sizeof(read_buf) - 1);
    if (bytes_read < 0) {
        perror("Failed to read from the device");
        close(fd);
        return 1;
    }

    // Null-terminate the received string
    read_buf[bytes_read] = '\0';

    printf("Received from device: %s\n", read_buf);

    // Close the device file
    close(fd);

    return 0;
}
