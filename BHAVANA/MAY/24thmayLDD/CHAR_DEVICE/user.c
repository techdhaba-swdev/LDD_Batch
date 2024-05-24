#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/char_device"
#define BUF_LEN 1024

int main() {
    int fd;
    char write_buf[] = "Hello, kernel. How are you?";
    char read_buf[BUF_LEN];

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    printf("Writing to the device: %s\n", write_buf);
    if (write(fd, write_buf, sizeof(write_buf)) < 0) {
        perror("Failed to write to the device");
        close(fd);
        return -1;
    }

    printf("Reading from the device...\n");
    if (read(fd, read_buf, sizeof(read_buf)) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return -1;
    }
    printf("Read from the device: %s\n", read_buf);

    close(fd);
    return 0;
}


