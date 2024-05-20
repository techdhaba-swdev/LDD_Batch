#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>

#define DEVICE_PATH "/dev/memmap_device"
#define DEVICE_MEMORY_SIZE 4096  // 4KB

void read_from_device(int fd) {
    char buffer[DEVICE_MEMORY_SIZE];
    ssize_t bytes_read;

    // Set file offset to the beginning
    lseek(fd, 0, SEEK_SET);

    // Read from device
    bytes_read = read(fd, buffer, DEVICE_MEMORY_SIZE);
    if (bytes_read < 0) {
        perror("Read failed");
        return;
    }

    buffer[bytes_read] = '\0';  // Null terminate the buffer
    printf("Read %ld bytes: %s\n", bytes_read, buffer);
}

void write_to_device(int fd, const char *data) {
    ssize_t bytes_written;

    // Set file offset to the beginning
    lseek(fd, 0, SEEK_SET);

    // Write to device
    bytes_written = write(fd, data, strlen(data));
    if (bytes_written < 0) {
        perror("Write failed");
        return;
    }

    printf("Written %ld bytes: %s\n", bytes_written, data);
}

void mmap_device(int fd) {
    char *map;
    char buffer[DEVICE_MEMORY_SIZE];

    // Memory map the device
    map = (char *)mmap(NULL, DEVICE_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap failed");
        return;
    }

    // Read from the mapped memory
    strncpy(buffer, map, DEVICE_MEMORY_SIZE);
    buffer[DEVICE_MEMORY_SIZE - 1] = '\0';  // Null terminate the buffer
    printf("Read from mmap: %s\n", buffer);

    // Modify the mapped memory
    strncpy(map, "Hello from mmap", DEVICE_MEMORY_SIZE - 1);
    printf("Written to mmap: %s\n", map);

    // Unmap the memory
    if (munmap(map, DEVICE_MEMORY_SIZE) < 0) {
        perror("munmap failed");
    }
}

int main() {
    int fd;

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device");
        return EXIT_FAILURE;
    }

    // Write to the device
    write_to_device(fd, "Hello, kernel space!");

    // Read from the device
    read_from_device(fd);

    // Memory map the device
    mmap_device(fd);

    // Close the device
    close(fd);
    return EXIT_SUCCESS;
}
