#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DEVICE "/dev/led_dev"

int main() {
    int fd;
    char led_value;
    char command;

    // Open the LED device
    fd = open(DEVICE, O_RDWR);
    if (fd == -1) {
        perror("Failed to open LED device");
        return EXIT_FAILURE;
    }

    // Read the current LED state
    if (read(fd, &led_value, sizeof(led_value)) != sizeof(led_value)) {
        perror("Failed to read LED state");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Current LED state: %c\n", led_value);

    // Ask the user for the desired state
    printf("Enter 1 to turn on the LED or 0 to turn it off: ");
    scanf(" %c", &command);

    // Validate user input
    if (command != '0' && command != '1') {
        fprintf(stderr, "Invalid command. Use 0 to turn off the LED, 1 to turn it on.\n");
        close(fd);
        return EXIT_FAILURE;
    }

    // Write the new value to the LED device
    if (write(fd, &command, sizeof(command)) != sizeof(command)) {
        perror("Failed to change LED state");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("LED state changed to %c\n", command);

    // Close the device
    close(fd);
    return EXIT_SUCCESS;
}
