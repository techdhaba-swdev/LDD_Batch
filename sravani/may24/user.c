#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_FILE "/dev/mychardev"
#define BUFFER_SIZE 1024

int main() {
    int fd;
    char write_buffer[] = "Hello welcome back";
    char read_buffer[BUFFER_SIZE];

    // Open the device file
    fd = open(DEVICE_FILE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return -1;
    }

    // Write data to the device
    if (write(fd, write_buffer, strlen(write_buffer)) < 0) {
        perror("Failed to write to the device");
        close(fd);
        return -1;
    }

    // Read data from the device
    if (read(fd, read_buffer, BUFFER_SIZE) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return -1;
    }

    // Print the data read from the device
    printf("Data read from device: %s\n", read_buffer);

    // Close the device file
    close(fd);

    return 0;
}
