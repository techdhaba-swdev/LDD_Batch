#include <stdio.h>      // Standard I/O operations
#include <fcntl.h>      // File control operations
#include <sys/mman.h>   // Memory management operations
#include <unistd.h>     // Standard symbolic constants and types
#include <string.h>     // String manipulation functions

#define DEVICE_PATH "/dev/mmap_prog"   // Path to the character device
#define MEMORY_SIZE 4096                // Size of the memory region to map (4KB)

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);    // Open the device file in read/write mode
    if (fd < 0) {
        perror("open");     // Print error message if opening the device file fails
        return -1;
    }

    void *mapped_memory = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    // Map the device file into memory
    // - NULL: Kernel chooses the address
    // - MEMORY_SIZE: Size of the mapping
    // - PROT_READ | PROT_WRITE: Access permissions (read and write)
    // - MAP_SHARED: Changes to the mapped memory are visible to other processes
    // - fd: File descriptor of the device file
    // - 0: Offset within the file (start from the beginning)

    if (mapped_memory == MAP_FAILED) {
        perror("mmap");     // Print error message if memory mapping fails
        close(fd);           // Close the device file
        return -1;
    }

    // Example: Writing to the mapped memory
    strcpy((char *)mapped_memory, "Hello from user space!");
    // Copy the string "Hello from user space!" to the mapped memory

    // Example: Reading from the mapped memory
    printf("Read from device: %s\n", (char *)mapped_memory);
    // Print the content of the mapped memory

    if (munmap(mapped_memory, MEMORY_SIZE) == -1) {
        perror("munmap");    // Print error message if unmapping memory fails
    }

    close(fd);              // Close the device file
    return 0;               // Return success
}

