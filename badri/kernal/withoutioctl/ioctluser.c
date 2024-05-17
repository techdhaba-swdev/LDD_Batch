#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char message[100] = "New message for the driver";

    fd = open("/dev/simple_char_driver", O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    // Write message directly to the device
    write(fd, message, sizeof(message));

    close(fd);
    return 0;
}
