#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

// Define the same structure used in the kernel module
struct user_data {
    int value;
    char message[20];
};

#define DEVICE_NAME "/dev/data_transfer"

int main() {
    int fd;
    struct user_data data;
    ssize_t ret;

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Prepare data to be written
    data.value = 42;
    strncpy(data.message, "Hello, kernel!", sizeof(data.message) - 1);
    data.message[sizeof(data.message) - 1] = '\0';

    // Write data to the device
    ret = write(fd, &data, sizeof(data));
    if (ret < 0) {
        perror("Failed to write data to the device");
        close(fd);
        return EXIT_FAILURE;
    }
    printf("Data written to device: value = %d, message = %s\n", data.value, data.message);

    // Clear the data structure
    memset(&data, 0, sizeof(data));

    // Read data from the device
    ret = read(fd, &data, sizeof(data));
    if (ret < 0) {
        perror("Failed to read data from the device");
        close(fd);
        return EXIT_FAILURE;
    }
    printf("Data read from device: value = %d, message = %s\n", data.value, data.message);

    // Close the device file
    close(fd);
    return EXIT_SUCCESS;
}
