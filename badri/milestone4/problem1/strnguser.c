#include <stdio.h> // Include the standard input/output library.
#include <fcntl.h> // Include the file control library for file handling.
#include <unistd.h> // Include the POSIX library for system calls.
#include <string.h> // Include the string manipulation library.
#include <errno.h> // Include errno.h for error handling.

#define DEVICE_NAME "/dev/reversing_string" // Define the device file path.
#define MAX_LENGTH 100 // Define the maximum length of strings.

int main() { // Main function.
    int fd; // File descriptor for the device file.
    char input_string[MAX_LENGTH]; // Buffer for input string.
    char reversed_string[MAX_LENGTH]; // Buffer for reversed string.

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR); // Open the device file for reading and writing.
    if (fd < 0) { // Check if opening the file failed.
        perror("Failed to open device file"); // Print an error message.
        return 1; // Return 1 to indicate failure.
    }

    printf("Enter a string to reverse: "); // Prompt the user to enter a string.

    // Read input from stdin
    if(fgets(input_string, MAX_LENGTH, stdin) == NULL) { // Read input from the user.
        perror("Failed to read input string"); // Print an error message if reading fails.
        close(fd); // Close the file descriptor before returning.
        return 1; // Return 1 to indicate failure.
    }

    // Write the input string to the device
    if(write(fd, input_string, strlen(input_string)) < 0) { // Write the input string to the device file.
        perror("Failed to write to device"); // Print an error message if writing fails.
        close(fd); // Close the file descriptor before returning.
        return 1; // Return 1 to indicate failure.
    }

    // Read the reversed string from the device
    if(read(fd, reversed_string, MAX_LENGTH) < 0) { // Read the reversed string from the device file.
        perror("Failed to read from device"); // Print an error message if reading fails.
        close(fd); // Close the file descriptor before returning.
        return 1; // Return 1 to indicate failure.
    }

    printf("Reversed string received from device: %s\n", reversed_string); // Print the reversed string.

    // Close the device file
    if(close(fd) < 0) { // Close the device file.
        perror("Failed to close device file"); // Print an error message if closing fails.
        return 1; // Return 1 to indicate failure.
    }

    return 0; // Return 0 to indicate success.
}
