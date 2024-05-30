#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
    char buffer[256];
    int fd = open("/dev/mychardev", O_RDWR);

    if (fd < 0) {
        perror("Error opening device");
        return 1;
    }

    // Read from the device
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead > 0) {
        printf("Read from device: %.*s\n", (int)bytesRead, buffer);
    } else {
        perror("Error reading from device");
    }

    // Write to the device
    const char* message = "Hello from user space!";
    ssize_t bytesWritten = write(fd, message, strlen(message));
    if (bytesWritten > 0) {
        printf("Wrote to device: %.*s\n", (int)bytesWritten, message);
    } else {
        perror("Error writing to device");
    }

    close(fd);
    return 0;
}


