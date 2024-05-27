#include <stdio.h>      
#include <stdlib.h>     
#include <fcntl.h>      
#include <unistd.h>     
#include <string.h>     

#define DEVICE_NAME "/dev/char_driver"  
#define MAX_SIZE 100                     // Size of the buffer

int main() {
    int fd;                                    // File descriptor
    char write_buffer[MAX_SIZE] = "HELLO, DEVICE SPACE.";            // Buffer for writing data
    char read_buffer[MAX_SIZE];             // Buffer for reading data
    ssize_t bytes_written, bytes_read;         // Number of bytes written and read

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");   // Print error if opening fails
        return EXIT_FAILURE;
    }

    
    // Write data to the device
    bytes_written = write(fd, write_buffer, strlen(write_buffer));
    if (bytes_written < 0) {
        perror("Failed to write to the device"); // Print error if writing fails
        close(fd);                               // Close the file
        return EXIT_FAILURE;
    }
    printf("Wrote %ld bytes to the device\n", bytes_written);

    // Read data from the device
    bytes_read = read(fd, read_buffer, MAX_SIZE);
    if (bytes_read < 0) {
        perror("Failed to read from the device"); // Print error if reading fails
        close(fd);                                // Close the file
        return EXIT_FAILURE;
    }

    
    printf("Read %ld bytes from the device:%s\n", bytes_read, read_buffer);

    // Close the device file
    close(fd);
    return EXIT_SUCCESS;
}
