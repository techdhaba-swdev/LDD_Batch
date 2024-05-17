
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

#define DEVICE_NAME "/dev/reverse_string"
#define MAX_LENGTH 100
#define IOCTL_REVERSE_STRING _IOR('R', 1, char *)

int main() {
    int fd;
    char input_string[MAX_LENGTH];
    char reversed_string[MAX_LENGTH];

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device file");
        return 1;
    }

    printf("Enter a string to reverse: ");
    fgets(input_string, MAX_LENGTH, stdin);

    // Call ioctl to reverse the string
    if (ioctl(fd, IOCTL_REVERSE_STRING, input_string) < 0) {
        perror("IOCTL failed");
        close(fd);
        return 1;
    }

    // Read the reversed string from the device
    read(fd, reversed_string, MAX_LENGTH);

    printf("Reversed string received from device: %s\n", reversed_string);
    close(fd);

    return 0;
}
