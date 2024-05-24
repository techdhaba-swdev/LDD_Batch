#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE "/dev/chardev"

int main() {
    int fd;
    char write_buf[80], read_buf[80];

    fd = open(DEVICE, O_RDWR);
    if (fd == -1) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    printf("Enter a message to write to the device: ");
    fgets(write_buf, sizeof(write_buf), stdin);
    write_buf[strcspn(write_buf, "\n")] = 0; // Remove newline character

    if (write(fd, write_buf, strlen(write_buf)) == -1) {
        perror("Failed to write the message to the device");
        close(fd);
        return EXIT_FAILURE;
    }

    if (read(fd, read_buf, sizeof(read_buf)) == -1) {
        perror("Failed to read the message from the device");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("The received message is: %s\n", read_buf);

    close(fd);
    return EXIT_SUCCESS;
}
