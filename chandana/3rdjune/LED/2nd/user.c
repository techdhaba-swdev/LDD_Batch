#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

#define LED_DEV "/dev/led_dev"

void print_usage(const char *progname) {
    fprintf(stderr, "Usage: %s <read|write> <0|1>\n", progname);
}

int main(int argc, char *argv[]) {
    int fd, ret;
    char value;

    if (argc < 2 || (strcmp(argv[1], "read") != 0 && strcmp(argv[1], "write") != 0)) {
        print_usage(argv[0]);
        return 1;
    }

    // Open the device file
    fd = open(LED_DEV, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    if (strcmp(argv[1], "write") == 0) {
        if (argc != 3 || (argv[2][0] != '0' && argv[2][0] != '1')) {
            print_usage(argv[0]);
            close(fd);
            return 1;
        }

        value = argv[2][0]; // '0' or '1'

        // Write the value to the device
        ret = write(fd, &value, sizeof(value));
        if (ret < 0) {
            perror("write");
            close(fd);
            return 1;
        }

        printf("LED state set to %c\n", value);
    } else {
        // Read the value from the device
        ret = read(fd, &value, sizeof(value));
        if (ret < 0) {
            perror("read");
            close(fd);
            return 1;
        }

        printf("LED state is %c\n", value);
    }

    // Close the device file
    close(fd);
    return 0;
}
