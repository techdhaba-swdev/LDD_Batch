#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DEVICE_PATH "/dev/my_device"
#define MEMORY_SIZE 4096  // 4KB

int main() {
    int fd;
    char *mapped_memory;
    ssize_t bytes;
    char read_buffer[MEMORY_SIZE];
    const char *write_buffer = "Hello from user space!";

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    // Map the device memory
    mapped_memory = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_memory == MAP_FAILED) {
        perror("Failed to map the device memory");
        close(fd);
        return -1;
    }

    // Write to the device memory
    memcpy(mapped_memory, write_buffer, strlen(write_buffer) + 1);
    printf("Message written to the device :%s\n",write_buffer);

    // Read from the device memory
    bytes = read(fd, read_buffer, sizeof(read_buffer));
    if (bytes < 0) {
        perror("Failed to read from the device");
    } else {
        printf("Read from device: %s\n", read_buffer);
    }

    // Unmap the device memory and close the device
    if (munmap(mapped_memory, MEMORY_SIZE) == -1) {
        perror("Failed to unmap the device memory");
    }
    close(fd);

    return 0;
}
