#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/rev_string"

int main() {
    int fd;
    char buffer[256];

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return errno;
    }

    // Read the original string from the kernel module
    read(fd, buffer, sizeof(buffer));
    printf("Original string from kernel: %s\n", buffer);

    // Reverse the string locally
    int len = strlen(buffer);
    int start = 0;
    int end = len - 1;
    char temp;
    while (start < end) {
        temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }

    // Print the reversed string
    printf("Reversed string locally: %s\n", buffer);

    // Close the device file
    close(fd);

    return 0;
}
