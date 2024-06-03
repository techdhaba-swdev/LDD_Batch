#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEVICE_PATH "/dev/led_dev2"

// Function to set the LED state
void set_led_state(int state) {
    int fd = open(DEVICE_PATH, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open the device file");
        exit(EXIT_FAILURE);
    }

    char value = (char)state;
    ssize_t ret = write(fd, &value, sizeof(value));
    if (ret == -1) {
        perror("Failed to write to the device file");
        close(fd);
        exit(EXIT_FAILURE);
    } else if (ret != sizeof(value)) {
        fprintf(stderr, "Partial write to the device file\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("LED state set to %d\n", state);
    close(fd);
}

// Function to prompt the user for input and set the LED state accordingly
void prompt_user() {
    char input[10];
    int state;

    printf("Enter 1 to turn on the LED, 0 to turn off the LED: ");
    fgets(input, sizeof(input), stdin);

    // Convert input to integer and validate
    state = atoi(input);
    if (state != 0 && state != 1) {
        fprintf(stderr, "Invalid input. Please enter 0 or 1.\n");
        exit(EXIT_FAILURE);
    }

    set_led_state(state);
}

int main() {
    prompt_user();
    return 0;
}
