#include <fcntl.h>      // File control options
#include <unistd.h>     // Standard symbolic constants and types
#include<stdio.h>
#include <string.h>
#define DEVICE_NAME "/dev/reverse" // Device file path
#define MAX_LENGTH 100                    // Maximum length of strings

int main() {
    int fd;                                // File descriptor for the device
    char input_string[MAX_LENGTH];         // Buffer to store user input
    char reversed_string[MAX_LENGTH];      // Buffer to store reversed string

    // Open the device file with read/write permissions
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device file"); // Print error message if open fails
        return 1;                              // Return 1 to indicate failure
    }

    printf("Enter a string to reverse: ");
    fgets(input_string, MAX_LENGTH, stdin);  // Read input string from user

    // Write the input string to the device
    write(fd, input_string, strlen(input_string));

    // Read the reversed string from the device
    read(fd, reversed_string, MAX_LENGTH);

    printf("Reversed string received from device: %s\n", reversed_string); // Print reversed string

    // Close the device file
    close(fd);

    return 0; // Return 0 to indicate successful execution
}

