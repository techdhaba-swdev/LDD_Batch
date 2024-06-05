#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("/dev/led_dev", O_RDWR);
    if (fd < 0) {
        perror("Error opening device");
        return 1;
    }

    char cmd;
    printf("Enter '1' to turn on LED, '0' to turn off LED: ");
    scanf("%c", &cmd);

    if (write(fd, &cmd, sizeof(cmd)) < 0) {
        perror("Error writing to device");
        close(fd);
        return 1;
    }

    char status;
    if (read(fd, &status, sizeof(status)) < 0) {
        perror("Error reading from device");
        close(fd);
        return 1;
    }

    printf("LED state: %c\n", status);

    close(fd);
    return 0;
}

