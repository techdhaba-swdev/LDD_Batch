#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define LED_DEV "/dev/led_dev"

int main(int argc, char *argv[]) {
    int fd;
    char value;

    if (argc != 2 || (argv[1][0] != '0' && argv[1][0] != '1')) {
        fprintf(stderr, "Usage: %s <0|1>\n", argv[0]);
        return 1;
    }

    // Open the device file in read-write mode
    fd = open(LED_DEV, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Set the value to write to the device
    value = argv[1][0];

    // Write the value to the device
    if (write(fd, &value, 1) != 1) {
        perror("write");
        close(fd);
        return 1;
    }

    // Read the current state of the LED
    if (read(fd, &value, 1) != 1) {
        perror("read");
        close(fd);
        return 1;
    }

    printf("LED set to %c\n", value);

    // Close the device file
    close(fd);
    return 0;
}
