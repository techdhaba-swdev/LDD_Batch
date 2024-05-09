#include <stdio.h>      // Include standard input-output library
#include <fcntl.h>      // Include file control library
#include <unistd.h>     // Include POSIX operating system API library
#include <string.h>     // Include string manipulation library

#define DEVICE_NAME "/dev/calculator"  // Define the device file name

int main() {
    int fd;             // File descriptor for the device file
    char operation;     // Character to store the arithmetic operation
    int operand1, operand2;  // Operands for the arithmetic operation
    char buffer[100];   // Buffer to store data read from or written to the device
    int nbytes;         // Number of bytes read from or written to the device

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);    // Open the device file with read and write permissions
    if (fd < 0) {                       // Check if the file descriptor is valid
        perror("Failed to open device file");  // Print an error message if opening fails
        return 1;                       // Return 1 to indicate failure
    }

    // Prompt the user for input
    printf("Enter the operation (+, -, *, /): ");  // Prompt the user to enter the operation
    scanf(" %c", &operation);                      // Read the operation character from user input
    printf("Enter operand 1: ");                   // Prompt the user to enter the first operand
    scanf("%d", &operand1);                        // Read the first operand from user input
    printf("Enter operand 2: ");                   // Prompt the user to enter the second operand
    scanf("%d", &operand2);                        // Read the second operand from user input

    // Write the operation and operands to the device
    sprintf(buffer, "%c %d %d", operation, operand1, operand2);  // Format operation and operands into a string
    nbytes = write(fd, buffer, strlen(buffer));    // Write the string to the device file
    if (nbytes < 0) {                               // Check if writing failed
        perror("Failed to write to device");        // Print an error message if writing fails
        close(fd);                                  // Close the device file
        return 1;                                   // Return 1 to indicate failure
    }

    // Read the result from the device
    printf("Result: ");                             // Print a message indicating the result
    nbytes = read(fd, buffer, sizeof(buffer));      // Read data from the device file into the buffer
    if (nbytes < 0) {                               // Check if reading failed
        perror("Failed to read from device");       // Print an error message if reading fails
        close(fd);                                  // Close the device file
        return 1;                                   // Return 1 to indicate failure
    }

    // Print the result
    printf("%s", buffer);                           // Print the result obtained from the device

    // Close the device file
    close(fd);                                      // Close the device file

    return 0;                                       // Return 0 to indicate success
}

