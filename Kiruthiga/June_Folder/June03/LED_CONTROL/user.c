#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define LED_DEV "/dev/led_dev"

int main(int argc, char *argv[]) {
    int fd, ret;
    char value, state;

    if (argc != 2 || (argv[1][0] != '0' && argv[1][0] != '1')) {
        fprintf(stderr, "Usage: %s <0|1>\n", argv[0]);
        return 1;
    }

    fd = open(LED_DEV, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Write the value to turn on/off the LED
    value = argv[1][0];
    ret = write(fd, &value, sizeof(value));
    if (ret < 0) {
        perror("write");
        close(fd);
        return 1;
    }

    // Read the current state of the LED
    ret = read(fd, &state, sizeof(state));
    if (ret < 0) {
        perror("read");
        close(fd);
        return 1;
    }

    printf("LED state: %c\n", state);

    close(fd);
    return 0;
}



