#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/my_ioctl_device"
#define IOCTL_SET_STRING _IOW('k', 1, char *)
#define IOCTL_GET_STRING _IOR('k', 2, char *)

int main() {
    int fd;
    char user_string[100]; // Buffer for string to kernel space
    char kernel_response[100]; // Buffer for string from kernel space

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Set the string to the kernel
    snprintf(user_string, sizeof(user_string), "Hello from user space!");
    if (ioctl(fd, IOCTL_SET_STRING, user_string) < 0) {
        perror("Failed to send string to the kernel");
        close(fd);
        return EXIT_FAILURE;
    }

    // Get the string from the kernel
    if (ioctl(fd, IOCTL_GET_STRING, kernel_response) < 0) {
        perror("Failed to get string from the kernel");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("String received from the kernel: %s\n", kernel_response);

    // Close the device
    close(fd);
    return EXIT_SUCCESS;
}
