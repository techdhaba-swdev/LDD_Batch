#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/my_device_memap"

int main() {
    int fd;
    char buffer[10];
    int number = 5; // Example number

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    // Write the number to the device
    sprintf(buffer, "%d", number);
    if (write(fd, buffer, sizeof(buffer)) < 0) {
        perror("Failed to write to the device");
        close(fd);
        return -1;
    }

    // Read the result from the device
    if (read(fd, buffer, sizeof(buffer)) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return -1;
    }

    // Convert the result to integer
    sscanf(buffer, "%d", &number);
    printf("Result: %d\n", number*2);

    // Close the device file
    close(fd);

    return 0;
}
