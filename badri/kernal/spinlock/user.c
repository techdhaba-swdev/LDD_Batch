#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/data_transfer"

struct user_data {
    int value;
    char message[20];
};

int main() {
    int fd;
    struct user_data data;

    // Open the character device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd == -1) {
        perror("Failed to open device");
        return EXIT_FAILURE;
    }

    // Write data to the device
    data.value = 123;
    strncpy(data.message, "Hello", sizeof(data.message));
    if (write(fd, &data, sizeof(data)) == -1) {
        perror("Failed to write to device");
        close(fd);
        return EXIT_FAILURE;
    }

    // Read data from the device
    if (read(fd, &data, sizeof(data)) == -1) {
        perror("Failed to read from device");
        close(fd);
        return EXIT_FAILURE;
    }

    // Display the read data
    printf("Received data from device:\n");
    printf("Value: %d\n", data.value);
    printf("Message: %s\n", data.message);

    // Close the device
    close(fd);

    return EXIT_SUCCESS;
}



