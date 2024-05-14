#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define DEVICE_PATH "/dev/reverse"
int main() {
    int fd;
    char message[100];
    char reverse[100];
    printf("Enter a string: ");
    fgets(message, 100, stdin);
    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }
    // Write the input value to the device
    write(fd, reverse, strlen(message));
    // Read the doubled value from the device
    read(fd, reverse, 100);
    printf("reverse string: %s\n",reverse);
    // Close the device file
    close(fd);
    return 0;
}
