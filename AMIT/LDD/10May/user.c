#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/string_char_dev"
#define IOCTL_SET_MSG _IOW('q', 1, char *)
#define IOCTL_REVERSE_MSG _IO('q', 2)

int main() {
    int fd;
    char read_buffer[100];
    char write_buffer[] = "Hello from user program!";

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Error opening device");
        return 1;
    }

    // Read from the device
    printf("Reading from device:\n");
    if (read(fd, read_buffer, sizeof(read_buffer)) < 0) {
        perror("Error reading from device");
        close(fd);
        return 1;
    }
    printf("Message from driver: %s\n", read_buffer);

 /*   // Write to the device
    printf("Writing to device:\n");
    if (write(fd, write_buffer, strlen(write_buffer)) < 0) {
        perror("Error writing to device");
        close(fd);
        return 1;
    }*/

    // Set a custom message using IOCTL
    char new_msg[] = "New message set via IOCTL";
    if (ioctl(fd, IOCTL_SET_MSG, new_msg) < 0) {
        perror("Error setting custom message");
        close(fd);
        return 1;
    }

    // Reverse the message using IOCTL
    if (ioctl(fd, IOCTL_REVERSE_MSG) < 0) {
        perror("Error reversing message");
        close(fd);
        return 1;
    }

    // Read the updated message
    printf("Reading updated message from device:\n");
    if (read(fd, read_buffer, sizeof(read_buffer)) < 0) {
        perror("Error reading from device");
        close(fd);
        return 1;
    }
    printf("Updated message from driver: %s\n", read_buffer);

    // Close the device file
    close(fd);
    return 0;
}
