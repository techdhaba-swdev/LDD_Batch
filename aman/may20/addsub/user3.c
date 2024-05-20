#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEVICE_PATH "/dev/calc_device"
#define BUFFER_SIZE 80

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int fd;
    char write_buffer[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];
    ssize_t bytes_written, bytes_read;

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd == -1) {
        handle_error("Failed to open device");
    }
    strcpy(write_buffer, "36 / 12");

    bytes_written = write(fd, write_buffer, strlen(write_buffer));
    if (bytes_written == -1) {
        handle_error("Failed to write to the device");
    }
    bytes_read = read(fd, read_buffer, BUFFER_SIZE - 1);
    if (bytes_read == -1) {
        handle_error("Failed to read from the device");
    }

    
    read_buffer[bytes_read] = '\0';
    printf("Result: %s\n", read_buffer);

   
    if (close(fd) == -1) {
        handle_error("Failed to close the device");
    }

    return 0;
}
