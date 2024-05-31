#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/addition_device"

int main() {
    int fd;
    char buffer[80];
    ssize_t bytes_read;

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd == -1) {
        perror("Failed to open the device");
        return 1;
    }

    // Prompt user to enter two numbers
    printf("Enter two numbers separated by space: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Write the numbers to the device
    if (write(fd, buffer, strlen(buffer)) == -1) {
        perror("Failed to write to the device");
        close(fd);
        return 1;
    }

    // Read the result from the device
    bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("Failed to read from the device");
        close(fd);
        return 1;
    }

    // Print the result
    printf("Result received from device: %s\n", buffer);

    // Close the device file
    close(fd);

    return 0;
}



