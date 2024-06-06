#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define DEVICE_PATH "/dev/simple_char"
#define BUFFER_SIZE 1024

int main() {
    int fd;
    char write_buffer[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];

    printf("Opening device...\n");
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device...");
        return errno;
    }

    printf("Enter a message to send to the device: ");
    scanf("%[^\n]%*c", write_buffer);

    printf("Writing message to the device...\n");
    int ret = write(fd, write_buffer, strlen(write_buffer));
    if (ret < 0) {
        perror("Failed to write the message to the device.");
        return errno;
    }

    printf("Reading from the device...\n");
    ret = read(fd, read_buffer, BUFFER_SIZE);
    if (ret < 0) {
        perror("Failed to read the message from the device.");
        return errno;
    }

    printf("The received message is: [%s]\n", read_buffer);

    printf("Closing device...\n");
    close(fd);
    return 0;
}
