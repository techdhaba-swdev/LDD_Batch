#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include<errno.h>

#define DEVICE_PATH "/dev/reverse_string"
#define IOCTL_REVERSE_STRING _IOR('k', 1, int)

#define MAX_STRING_LENGTH 100

int main()
{
    int fd;
    char original_string[MAX_STRING_LENGTH];
    char reversed_string[MAX_STRING_LENGTH];

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device.");
        return errno;
    }

    // Input the string to be reversed
    printf("Enter a string to reverse: ");
    fgets(original_string, sizeof(original_string), stdin);

    // Write the string to the kernel module
    if (write(fd, original_string, sizeof(original_string)) == -1) {
        perror("write failed");
        close(fd);
        return errno;
    }

    // Reverse the string in kernel module using IOCTL
    if (ioctl(fd, IOCTL_REVERSE_STRING) == -1) {
        perror("ioctl failed");
        close(fd);
        return errno;
    }

    // Read the reversed string from the kernel module
    if (read(fd, reversed_string, sizeof(reversed_string)) == -1) {
        perror("read failed");
        close(fd);
        return errno;
    }

    printf("Reversed string from kernel: %s\n", reversed_string);

    // Close the device file
    close(fd);

    return 0;
}

