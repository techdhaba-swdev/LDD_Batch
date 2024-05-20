#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/my_device_wr"
#define MEMORY_SIZE 4096  // 4KB

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // Example: Writing to the device
    const char *write_data = "Hello from user space via write!";
    ssize_t bytes_written = write(fd, write_data, strlen(write_data));
    if (bytes_written < 0) {
        perror("write");
        close(fd);
        return -1;
    }

    // Example: Reading from the device
    char read_data[MEMORY_SIZE];
    ssize_t bytes_read = read(fd, read_data, MEMORY_SIZE - 1);
    if (bytes_read < 0) {
        perror("read");
        close(fd);
        return -1;
    }

    read_data[bytes_read] = '\0';  // Null-terminate the read data
    printf("Read from device: %s\n", read_data);

    close(fd);
    return 0;
}
