#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NAME "/dev/add_device" // Define the device name

// Define a structure to hold the operation data
struct addition_operation {
    int num1;
    int num2;
    int sum;
};

int main() {
    struct addition_operation operation;
    int fd = open(DEVICE_NAME, O_RDWR); // Open the character device
    if (fd < 0) {
        perror("Failed to open the device"); // Print error message if opening device fails
        return -1;
    }

    for (int i = 0; i < 10; ++i) {
        // Prompt user for input
        printf("Enter first number for operation %d: ", i + 1);
        scanf("%d", &operation.num1); // Read first number
        printf("Enter second number for operation %d: ", i + 1);
        scanf("%d", &operation.num2); // Read second number
        
        // Write the operation structure to the device
        if (write(fd, &operation, sizeof(struct addition_operation)) < 0) {
            perror("Failed to write to the device");
            close(fd);
            return -1;
        }
        
        // Read the result structure from the device
        if (read(fd, &operation, sizeof(struct addition_operation)) < 0) {
            perror("Failed to read from the device");
            close(fd);
            return -1;
        }
        
        // Print the operation
        printf("Operation %d: %d + %d = %d\n", i + 1, operation.num1, operation.num2, operation.sum);
    }

    // Close the device
    close(fd);
    return 0;
}
