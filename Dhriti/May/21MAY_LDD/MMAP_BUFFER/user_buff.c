#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/mmep_buffer"
#define MEMORY_SIZE 4096  // 4KB

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <num1> <num2>\n", argv[0]);
        return -1;
    }

    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // Concatenate the two numbers into a single string
    char write_message[MEMORY_SIZE];
    snprintf(write_message, MEMORY_SIZE, "%s %s", argv[1], argv[2]);

    // Sending the numbers to the device
    if (write(fd, write_message, strlen(write_message)) < 0) {
        perror("write");
        close(fd);
        return -1;
    }

    // Reading the result of the addition
    char read_buffer[MEMORY_SIZE];
    ssize_t bytes_read = read(fd, read_buffer, MEMORY_SIZE);
    if (bytes_read < 0) {
        perror("read");
        close(fd);
        return -1;
    }
    read_buffer[bytes_read] = '\0';  // Null-terminate the string
    printf("Result of addition: %s\n", read_buffer);

    close(fd);
    return 0;
}
