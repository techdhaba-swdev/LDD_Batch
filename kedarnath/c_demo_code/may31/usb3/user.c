#include <stdio.h>
#include <stdlib.h>   
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEVICE_PATH "/dev/usb_example"
#define BUFFER_SIZE 512

int main() {
    int fd;
    char write_buf[BUFFER_SIZE] = "Hello, USB!";
    char read_buf[BUFFER_SIZE];
    ssize_t ret;

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return errno;
    }

    // Write to the device
    printf("Writing to the device: [%s]\n", write_buf);
    ret = write(fd, write_buf, strlen(write_buf));
    if (ret < 0) {
        perror("Failed to write to the device");
        close(fd);
        return errno;
    }

    // Read from the device
    printf("Reading from the device...\n");
    ret = read(fd, read_buf, BUFFER_SIZE - 1);
    if (ret < 0) {
        perror("Failed to read from the device");
        close(fd);
        return errno;
    }

    // Null-terminate the read buffer and print the read data
    read_buf[ret] = '\0';
    printf("Read from the device: [%s]\n", read_buf);

    // Close the device
    close(fd);
    return 0;
}




