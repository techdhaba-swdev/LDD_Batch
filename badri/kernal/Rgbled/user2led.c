#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define LED_DEV_PATH "/dev/led_dev"

int main() {
    int led_fd;
    char buffer[2];

    // Open the LED device
    led_fd = open(LED_DEV_PATH, O_RDWR);
    if (led_fd < 0) {
        perror("Failed to open LED device");
        return 1;
    }

    // Prompt user for input
    printf("Enter 1 to turn on the LED, 0 to turn off: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Write user input to LED device
    if (write(led_fd, buffer, sizeof(buffer)) < 0) {
        perror("Write failed");
        close(led_fd);
        return 1;
    }

    // Read LED state
    if (read(led_fd, buffer, sizeof(buffer)) < 0) {
        perror("Read failed");
        close(led_fd);
        return 1;
    }

    // Display LED state
    printf("LED state: %s\n", (buffer[0] == '1') ? "ON" : "OFF");

    // Close the LED device
    close(led_fd);

    return 0;
}
