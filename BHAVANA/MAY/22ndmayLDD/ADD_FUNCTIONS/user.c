#include <stdio.h>     // Standard I/O functions
#include <fcntl.h>     // File control options
#include <unistd.h>    // Symbolic constants and types
#include <string.h>    // String manipulation functions
#include <stdlib.h>    // Standard library functions

#define DEVICE_PATH "/dev/add10" // Path to the device file
#define MEMORY_SIZE 4096  // 4KB

// Structure to hold the operation data
struct operation {
    int num1;
    int num2;
    char operation;
};

int main() {
    int fd = open(DEVICE_PATH, O_RDWR); // Open the device file
    if (fd < 0) {
        perror("open"); // Print error message if opening fails
        return -1;
    }

    struct operation op;
    int result;
    char buffer[sizeof(struct operation)];

    for (int i = 0; i < 10; i++) { // Loop for 10 operations
        printf("Operation %d:\n", i + 1);
        printf("Enter first number: ");
        scanf("%d", &op.num1); // Read first number
        printf("Enter second number: ");
        scanf("%d", &op.num2); // Read second number
        op.operation = '+'; // Set the operation to addition

        // Copy operation data to buffer
        memcpy(buffer, &op, sizeof(struct operation));

        // Write data to the device
        if (write(fd, buffer, sizeof(buffer)) < 0) {
            perror("write"); // Print error message if writing fails
            close(fd); // Close the device file
            return -1;
        }

        // Read result from the device
        if (read(fd, &result, sizeof(result)) < 0) {
            perror("read"); // Print error message if reading fails
            close(fd); // Close the device file
            return -1;
        }

        printf("Result of %d + %d = %d\n", op.num1, op.num2, result); // Print the result
    }

    close(fd); // Close the device file
    return 0;
}


