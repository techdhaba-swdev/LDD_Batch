#include <stdio.h>      // Standard I/O operations
#include <fcntl.h>      // File control operations
#include <sys/mman.h>   // Memory management operations
#include <unistd.h>     // Standard symbolic constants and types
#include <string.h>     // String manipulation functions

#define DEVICE_PATH "/dev/mmap_device"   // Path to the character device
#define MEMORY_SIZE 4096                // Size of the memory region to map (4KB)



int main() {
    int fd = open(DEVICE_PATH, O_RDWR);    // Open the device file in read/write mode
    if (fd < 0) {
        perror("open");     // Print error message if opening the device file fails
        return -1;
    }
    int *mapped_memory;
  
    mapped_memory =(int *) mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    // Map the device file into memory
    // - NULL: Kernel chooses the address
    // - MEMORY_SIZE: Size of the mapping
    // - PROT_READ | PROT_WRITE: Access permissions (read and write)
    // - MAP_SHARED: Changes to the mapped memory are visible to other processes
    // - fd: File descriptor of the device
   


    if (mapped_memory == MAP_FAILED) {
        perror("mmap");     // Print error message if memory mapping fails
        close(fd);           // Close the device file
        return -1;
    }
    
    int result = *mapped_memory;
    printf("Output: %d\n", result);

    if (munmap(mapped_memory, MEMORY_SIZE) == -1) {
        perror("munmap");    // Print error message if unmapping memory fails
    }

    close(fd);              // Close the device file
    return 0;               // Return success
}

