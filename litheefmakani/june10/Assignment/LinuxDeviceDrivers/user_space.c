#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/sensor_temp"

int main() {
    int fd;
    int temp;

    // Open the device file
    fd = open(DEVICE_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open the device file");
        return EXIT_FAILURE;
    }

    // Read temperature from the device
    if (read(fd, &temp, sizeof(temp)) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }

    // Display the temperature
    printf("Current temperature: %d\n", temp);

    // Close the device file
    close(fd);

    return EXIT_SUCCESS;
}
