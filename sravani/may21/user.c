#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/my_device"
#define MEMORY_SIZE 4096  // 4KB

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // Example: Writing an integer to the device
    const char *write_message = "42";  // Initial number to write
    if (write(fd, write_message, strlen(write_message)) < 0) {
        perror("write");
        close(fd);
        return -1;
    }

    // Example: Reading the modified integer from the device
    char read_buffer[MEMORY_SIZE];
    ssize_t bytes_read = read(fd, read_buffer, MEMORY_SIZE);
    if (bytes_read < 0) {
        perror("read");
        close(fd);
        return -1;
    }
    read_buffer[bytes_read] = '\0';  // Null-terminate the string
    printf("Read from device: %s\n", read_buffer);

    // Example: Memory-mapped I/O
    void *mapped_memory = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_memory == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return -1;
    }

    // Example: Writing to the mapped memory
    strcpy((char *)mapped_memory, "Hello from mmap!");

    // Example: Reading from the mapped memory
    printf("Read from mmap: %s\n", (char *)mapped_memory);

    if (munmap(mapped_memory, MEMORY_SIZE) == -1) {
        perror("munmap");
    }

    close(fd);
    return 0;
}
