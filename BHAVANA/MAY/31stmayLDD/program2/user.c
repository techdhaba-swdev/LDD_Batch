#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define DEVICE "/dev/simple_char"

int main() {
    int fd;
    char buffer[80];

    fd = open(DEVICE, O_RDWR);
    if (fd == -1) {
        perror("Failed to open the device");
        return 1;
    }

    printf("Enter a string: ");
    fgets(buffer, 80, stdin);

    // Write to the device
    write(fd, buffer, strlen(buffer));

    // Read from the device
    read(fd, buffer, 80);
    printf("User: %s\n", buffer);

    close(fd);
    return 0;
}
