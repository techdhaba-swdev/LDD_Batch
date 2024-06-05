#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

#define LED_DEV "/dev/led_devs"

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <read|write>\n", prog_name);
}

int main(int argc, char *argv[]) {
    int fd, ret;
    char value;

    if (argc != 2 || (strcmp(argv[1], "read") != 0 && strcmp(argv[1], "write") != 0)) {
        print_usage(argv[0]);
        return 1;
    }

    // Open the device file
    fd = open(LED_DEV, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    if (strcmp(argv[1], "read") == 0) {
        // Read the current LED state
        ret = read(fd, &value, sizeof(value));
        if (ret < 0) {
            perror("read");
            close(fd);
            return 1;
        }
        printf("Current LED state: %c\n", value);
    } else if (strcmp(argv[1], "write") == 0) {
        // Prompt user to turn on or off the LED
        printf("Enter LED state (0 for off, 1 for on): ");
        scanf(" %c", &value);

        if (value != '0' && value != '1') {
            fprintf(stderr, "Invalid input. Please enter 0 or 1.\n");
            close(fd);
            return 1;
        }

        // Write the new LED state
        ret = write(fd, &value, sizeof(value));
        if (ret < 0) {
            perror("write");
            close(fd);
            return 1;
        }
        printf("LED state set to %c\n", value);
    }

    // Close the device file
    close(fd);
    return 0;
}
