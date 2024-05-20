#include <stdio.h> // Standard I/O functions
#include <stdlib.h> // Standard library functions, including EXIT_FAILURE and EXIT_SUCCESS
#include <fcntl.h> // File control options (for open flags)
#include <unistd.h> // POSIX operating system API (for close, read, write, etc.)
#include <poll.h> // Polling functions and structures
#include <string.h> // String manipulation functions (for strlen)

// Define the device file path
#define DEVICE "/dev/example_char_device"

// Define the buffer length for reading data
#define BUF_LEN 80

int main() {
    // Open the device file with read and write permissions
    int fd = open(DEVICE, O_RDWR);
    if (fd == -1) { // Check if opening the device failed
        perror("Failed to open device"); // Print error message
        return EXIT_FAILURE; // Exit the program with failure status
    }

    // Create and configure the pollfd structure for the device
    struct pollfd pfd;
    pfd.fd = fd; // Set the file descriptor to the opened device
    pfd.events = POLLIN | POLLOUT; // Set events to poll for: data to read and ready to write

    // Allocate a buffer for reading data
    char buffer[BUF_LEN];

    // Enter an infinite loop to continuously poll the device
    while (1) {
        // Call poll with a 5-second timeout (5000 milliseconds)
        int ret = poll(&pfd, 1, 5000); // Poll for events on the device
        if (ret == -1) { // Check if poll returned an error
            perror("poll"); // Print error message
            close(fd); // Close the device file
            return EXIT_FAILURE; // Exit the program with failure status
        } else if (ret == 0) { // Check if poll timed out
            printf("Timeout occurred! No data within 5 seconds.\n"); // Print timeout message
        } else { // Poll detected an event
            if (pfd.revents & POLLIN) { // Check if there is data to read
                // Read data from the device into the buffer
                int bytes_read = read(fd, buffer, BUF_LEN);
                if (bytes_read > 0) { // Check if read was successful
                    buffer[bytes_read] = '\0'; // Null-terminate the string
                    printf("Read data: %s\n", buffer); // Print the read data
                }
            }

            if (pfd.revents & POLLOUT) { // Check if the device is ready to write
                // Prepare data to write to the device
                char write_data[] = "Hello, device!";
                // Write data to the device
                int bytes_written = write(fd, write_data, strlen(write_data));
                if (bytes_written > 0) { // Check if write was successful
                    printf("Written data: %s\n", write_data); // Print the written data
                }
            }
        }
    }

    // Close the device file (this line is unreachable but would be executed if the loop exits)
    close(fd);
    return EXIT_SUCCESS; // Exit the program with success status
}
