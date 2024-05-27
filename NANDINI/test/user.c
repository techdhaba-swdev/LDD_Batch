#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE "/dev/char_dev"

int main() {
    int fd;
    char write_buf[] = "Hello, kernel!";
    char read_buf[80];
    ssize_t ret;

    fd = open(DEVICE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device...");
        return errno;
    }

    ret = write(fd, write_buf, sizeof(write_buf));
    if (ret < 0) {
        perror("Failed to write the message to the device.");
        close(fd);
        return errno;
    }

    printf("Message written to the device: %s\n", write_buf);

    ret = read(fd, read_buf, sizeof(read_buf));
    if (ret < 0) {
        perror("Failed to read the message from the device.");
        close(fd);
        return errno;
    }

    printf("Message read from the device: %s\n", read_buf);

    close(fd);
    return 0;
}
