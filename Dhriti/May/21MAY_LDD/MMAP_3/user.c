#include <stdio.h>          // Header for standard I/O functions
#include <stdlib.h>         // Header for standard library functions (like EXIT_FAILURE)
#include <fcntl.h>          // Header for file control options (like open flags)
#include <unistd.h>         // Header for POSIX operating system API (like close)
#include <sys/mman.h>       // Header for memory management declarations (like mmap)
#include <string.h>         // Header for string handling functions (like strcpy)

#define DEVICE_PATH "/dev/mmap_char_device" // Path to the device file
#define BUF_SIZE 4096                      // Size of the memory buffer (4KB)

int main() {
    // Open the device file with read/write access
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {                         // If opening the device file failed
        perror("open");                   // Print the error message
        return EXIT_FAILURE;              // Exit with a failure code
    }

    // Memory-map the device file to user space
    char *mapped_mem = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_mem == MAP_FAILED) {       // If mmap failed
        perror("mmap");                   // Print the error message
        close(fd);                        // Close the device file descriptor
        return EXIT_FAILURE;              // Exit with a failure code
    }

    // Writing a message to the device memory
    const char *message = "Hello from user space!"; // Message to be written
    strcpy(mapped_mem, message);          // Copy the message to the mapped memory
    printf("Written to device: %s\n", message); // Print confirmation

    // Reading the message back from the device memory
    printf("Read from device: %s\n", mapped_mem); // Print the content of the mapped memory

    // Unmap the device memory
    if (munmap(mapped_mem, BUF_SIZE) == -1) { // If unmapping failed
        perror("munmap");                // Print the error message
    }

    close(fd);                           // Close the device file descriptor
    return EXIT_SUCCESS;                 // Exit with a success code
}
