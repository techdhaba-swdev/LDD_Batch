#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#define DEVICE_NAME "/dev/my_device"

int main() {
    int fd;
    int data = 10; // Sample data to send to kernel

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    // Define an ioctl command
    #define MY_IOCTL_CMD _IOW('M', 1, int)

    // Send data to the kernel using ioctl
    if (ioctl(fd, MY_IOCTL_CMD, &data) < 0) {
        perror("ioctl");
        exit(1);
    }

    // Simulate user-space work (replace with actual work)
    printf("User program doing some work...\n");
    usleep(2000000); // Simulate work with usleep

    // Close the device file
    close(fd);

    return 0;

