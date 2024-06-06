#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define LED_DEV "/dev/led_dev"

#define CMD_TURN_ON '1'
#define CMD_TURN_OFF '0'
#define CMD_READ 'r'

int main(int argc, char *argv[]) {
    int fd, ret;
    char value;

    // Check if the correct number of arguments and command is provided
    if (argc != 2 || (argv[1][0] != CMD_TURN_ON && argv[1][0] != CMD_TURN_OFF && argv[1][0] != CMD_READ)) {
        // Print usage message to stderr
        fprintf(stderr, "Usage: %s <0|1|r>\n", argv[0]);
        return 1;
    }

    // Open the device file based on the command
    fd = open(LED_DEV, (argv[1][0] == CMD_READ) ? O_RDONLY : O_WRONLY);
    if (fd < 0) {
        perror("open"); // Print error message for open failure
        return 1;
    }

    if (argv[1][0] != CMD_READ) { // If command is not read
        value = argv[1][0]; // Get the value to be written based on the command line argument
        ret = write(fd, &value, sizeof(value)); // Write the value to the device file
        if (ret < 0) {
            perror("write"); // Print error message for write failure
            close(fd); // Close the file descriptor
            return 1;
        }
    } else { // If command is read
        ret = read(fd, &value, sizeof(value)); // Read the value from the device file
        if (ret < 0) {
            perror("read"); // Print error message for read failure
            close(fd); // Close the file descriptor
            return 1;
        }
        printf("LED state: %c\n", value); // Print the LED state
    }

    close(fd); // Close the file descriptor
    return 0; // Return success
}

