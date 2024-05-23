#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NAME "/dev/operation_device"

// Define a structure to hold the operation data
struct operation {
    int num1;
    int num2;
    char operator;
    int result;
};

// Function to perform operation
void perform_operation(int fd, struct operation *op) {
    // Write the operation structure to the device
    if (write(fd, op, sizeof(struct operation)) < 0) {
        perror("Failed to write to the device");
        return;
    }
    
    // Read the result structure from the device
    if (read(fd, op, sizeof(struct operation)) < 0) {
        perror("Failed to read from the device");
        return;
    }
    
    // Print the result
    printf("Result: %d %c %d = %d\n", op->num1, op->operator, op->num2, op->result);
}

int main() {
    struct operation op;
    int fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    // Predefined expressions
    const char *expressions[] = {"10+5", "10-5", "20+5", "20-5", "30+5", "30-5", "40+5", "40-5", "50+5", "50-5"};
    
    for (int i = 0; i < 10; i++) {
        // Parse the expression
        if (sscanf(expressions[i], "%d %c %d", &op.num1, &op.operator, &op.num2) != 3) {
            printf("Invalid expression: %s\n", expressions[i]);
            continue;
        }

        // Perform the operation
        perform_operation(fd, &op);
    }

    close(fd);
    return 0;
}
