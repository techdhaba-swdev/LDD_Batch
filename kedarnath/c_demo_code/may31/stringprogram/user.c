#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/my_device" 

int main() {
    int fd;
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from fgets
    str[strcspn(str, "\n")] = '\0';

    fd = open(DEVICE_PATH, O_WRONLY);
    if (fd < 0) {
        perror("Failed to open the device");
        return 1;
    }

    if (write(fd, str, strlen(str)) < 0) {
        perror("Failed to write to the device");
        close(fd);
        return 1;
    }

    printf("String sent to kernel module: %s\n", str);
    close(fd);
    return 0;
}



