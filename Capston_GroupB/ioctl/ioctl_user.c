//Header files for the api,structures...which we use
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/my_ioctl_device"
#define IOCTL_MAGIC 'k' //Declared magic number(A Unique number that used to differentiate Between IOCTL calls)
//IOCTL Macros which takes magic number,command number,type of data
#define IOCTL_SET_STRING _IOW(IOCTL_MAGIC, 2, char *) 
#define IOCTL_GET_STRING _IOR(IOCTL_MAGIC, 3, char *)

int main() {
    int fd; //declared a file descriptor
    char user_string[100]; // Buffer to send string to kernel space
    char kernel_response[100]; // Buffer to store string from kernel space

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Set the string to the kernel
    snprintf(user_string, sizeof(user_string), "Hello, Kernel!");
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
