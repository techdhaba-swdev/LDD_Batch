#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/memoryrw_device"
#define MEMORY_SIZE 4096 // 4KB

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // Example: Writing to the mapped memory
    char write_buffer[] = "Hello from user space!";
    ssize_t bytes_written = write(fd, write_buffer, strlen(write_buffer));
    if (bytes_written == -1) {
        perror("write");
        close(fd);
        return -1;
    }

    // Example: Reading from the mapped memory
    char read_buffer[MEMORY_SIZE];
    ssize_t bytes_read = read(fd, read_buffer, MEMORY_SIZE);
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        return -1;
    }
    printf("Read from device: %s\n", read_buffer);

    close(fd);
    return 0;
}
