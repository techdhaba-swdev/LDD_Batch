#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include<errno.h>
#define DEVICE_PATH "/dev/device_memory" 
#define MEMORY_SIZE 4096  // 4KB

ssize_t my_device_write(int fd, const char *buf, size_t len) {
    ssize_t bytes_written = 0;

    // Validate input parameters
    if (!buf || len == 0) {
        return -EINVAL; // Invalid argument
    }

    // Write data to the device
    bytes_written = write(fd, buf, len);
    if (bytes_written < 0) {
        perror("Error writing to device");
        return bytes_written;
    }

    printf("Wrote %zd bytes to device\n", bytes_written);
    return bytes_written;
}


int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }
       const char *message = "Hello, kernel! this is tony stark..!!"; // Example message to write
        ssize_t result = my_device_write(fd, message, strlen(message));
    if (result < 0) {
        close(fd);
        return result;
    }

    void *mapped_memory = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_memory == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return -1;
    }

    // Example: Writing to the mapped memory
    strcpy((char *)mapped_memory, "Hello from user space!");

    // Example: Reading from the mapped memory
    printf("Read from device: %s\n", (char *)mapped_memory);

    // Modify the mapped memory (write example)
//    snprintf(mapped_memory, MEMORY_SIZE, "Hello, kernel! this is tony stark");

    if (munmap(mapped_memory, MEMORY_SIZE) == -1) {
        perror("munmap");
    }

    close(fd);
    return 0;
}


