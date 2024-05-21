#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>

#define DEVICE_NAME "/dev/my_device"
#define DEVICE_MEMORY_SIZE 4096

int main() {
    int fd;
    char write_buffer[] = "Hello from user space!";
    char read_buffer[DEVICE_MEMORY_SIZE];
    void *mapped_memory;
    ssize_t ret;

    // Open the device
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return errno;
    }

    // Write to the device
    ret = write(fd, write_buffer, strlen(write_buffer));
    if (ret < 0) {
        perror("Failed to write to the device");
        close(fd);
        return errno;
    }
    printf("Wrote %zu bytes to the device\n", ret);

    // Read from the device
    lseek(fd, 0, SEEK_SET);  // Reset file offset
    ret = read(fd, read_buffer, sizeof(read_buffer) - 1);
    if (ret < 0) {
        perror("Failed to read from the device");
        close(fd);
        return errno;
    }
    read_buffer[ret] = '\0';
    printf("Read %zu bytes from the device: %s\n", ret, read_buffer);

    // Memory map the device
    mapped_memory = mmap(NULL, DEVICE_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_memory == MAP_FAILED) {
        perror("Failed to mmap the device");
        close(fd);
        return errno;
    }

    // Interact with the mapped memory
    printf("Mapped memory contains: %s\n", (char *)mapped_memory);

    // Clean up
    if (munmap(mapped_memory, DEVICE_MEMORY_SIZE) < 0) {
        perror("Failed to munmap the device");
        close(fd);
        return errno;
    }

    close(fd);
    return 0;
}
