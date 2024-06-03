#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DEVICE "/dev/led_dev"

int main(int argc, char *argv[]) {
    int fd;
    char led_value;

    // Check for correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <0|1>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert argument to integer and validate
    led_value = atoi(argv[1]);
    if (led_value != 0 && led_value != 1) {
        fprintf(stderr, "Invalid value. Use 0 to turn off the LED, 1 to turn it on.\n");
        return EXIT_FAILURE;
    }

    // Open the LED device
    fd = open(DEVICE, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open LED device");
        return EXIT_FAILURE;
    }

    // Write the value to the LED device
    if (write(fd, &led_value, sizeof(led_value)) != sizeof(led_value)) {
        perror("Failed to change LED state");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("LED state changed to %d\n", led_value);

    // Close the device
    close(fd);
    return EXIT_SUCCESS;
}
