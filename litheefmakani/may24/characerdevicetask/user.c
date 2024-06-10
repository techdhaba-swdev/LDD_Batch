#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/mychardev"

int main()
{
    int fd;
    char buffer[1024];
    ssize_t bytes_read, bytes_written;

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd == -1) {
        perror("Failed to open the device file");
        return EXIT_FAILURE;
    }

    // Write data to the device
    bytes_written = write(fd, "Hello, device!", 14);
    if (bytes_written == -1) {
        perror("Failed to write to the device");
        close(fd);
        return EXIT_FAILURE;
    }

    // Read data from the device
    bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Read from device: %s\n", buffer);

    // Close the device file
    close(fd);

    return EXIT_SUCCESS;
}
