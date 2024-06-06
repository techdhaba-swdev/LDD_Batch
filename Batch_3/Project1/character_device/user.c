#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library for memory allocation, process control, etc.
#include <fcntl.h> // File control options
#include <unistd.h> // POSIX API for system calls
#include <sys/ioctl.h> // IOCTL system call

// Define the device path
#define DEVICE_PATH "/dev/my_ioctls_device"

// Define IOCTL magic number and commands
#define IOCTL_MAGIC 'k'
#define IOCTL_BASIC_ARITH _IOWR(IOCTL_MAGIC, 1, int[3])
#define IOCTL_ADVANCED_ARITH _IOWR(IOCTL_MAGIC, 2, int[3])

// Basic Arithmetic IOCTLs
#define IOCTL_ADD _IOWR(IOCTL_BASIC_ARITH, 1, int[3])
#define IOCTL_SUB _IOWR(IOCTL_BASIC_ARITH, 2, int[3])


// Advanced Arithmetic IOCTLs
#define IOCTL_MUL _IOWR(IOCTL_ADVANCED_ARITH, 1, int[3])
#define IOCTL_DIV _IOWR(IOCTL_ADVANCED_ARITH, 2, int[3])
#define IOCTL_MOD _IOWR(IOCTL_ADVANCED_ARITH, 3, int[3])

// Define a type for the operation functions
/*Liskov Substitution Principle (LSP)
Principle: Objects of a superclass should be replaceable with objects of a subclass without affecting the functionality of the program.
To achieve this principle: operation_func function pointer is used. Any function that matches the operation_func signature can be passed to execute_operation. This flexibility ensures that the program can substitute one operation function for another without Affecting the execute_operation function's implementation.
*/
typedef void (*operation_func)(int fd, int operand1, int operand2, int *result);

/*
 * Single Responsibility Principle (SRP): The `handle_input` function 
 * is responsible for handling user input only.
 */
void handle_input(char *operation, int *operand1, int *operand2) {
    printf("Enter operation (a: add, s: subtract, m: multiply, d: divide, o: modulus): ");
    scanf(" %c", operation); // Read the operation from the user
    printf("Enter operand1: ");
    scanf("%d", operand1); // Read the first operand from the user
    printf("Enter operand2: ");
    scanf("%d", operand2); // Read the second operand from the user
}

/*
 * Single Responsibility Principle (SRP): The `perform_operation` function 
 * is responsible for executing the IOCTL command and handling the result.
 */
void perform_operation(int fd, unsigned long cmd, int operand1, int operand2, int *result) {
    int values[3] = {operand1, operand2, 0}; // Array to hold operands and result

    if (ioctl(fd, cmd, &values) < 0) { // Execute the IOCTL command
        perror("Failed to execute ioctl"); // Print error message if IOCTL fails
        close(fd); // Close the file descriptor
        exit(EXIT_FAILURE); // Exit the program with failure status
    }

    *result = values[2]; // Set the result from the IOCTL command
}
/* Open/Closed Principle (OCP)
Principle: Software entities should be open for extension, but closed for modification.
To achieve this principle:Extend the IOCTL commands without modifying existing code by adding new IOCTL for each operations like add,subtract,multiply,divide.
*/
// Define functions for each operation using the `perform_operation` function
void add_operation(int fd, int operand1, int operand2, int *result) {
    perform_operation(fd, IOCTL_ADD, operand1, operand2, result);
}

void subtract_operation(int fd, int operand1, int operand2, int *result) {
    perform_operation(fd, IOCTL_SUB, operand1, operand2, result);
}

void multiply_operation(int fd, int operand1, int operand2, int *result) {
    perform_operation(fd, IOCTL_MUL, operand1, operand2, result);
}

void divide_operation(int fd, int operand1, int operand2, int *result) {
    perform_operation(fd, IOCTL_DIV, operand1, operand2, result);
}

void modulus_operation(int fd, int operand1, int operand2, int *result) {
    perform_operation(fd, IOCTL_MOD, operand1, operand2, result);
}

/*
 * Dependency Inversion Principle (DIP): The `execute_operation` function depends on the 
 * high-level `operation_func` type, allowing flexibility in which operation to execute.
 */
void execute_operation(operation_func op, int fd, int operand1, int operand2, int *result) {
    op(fd, operand1, operand2, result); // Execute the given operation function
}

/*
 * Single Responsibility Principle (SRP): The `display_result` function 
 * is responsible for displaying the result to the user.
 */
void display_result(int result) {
    printf("Result: %d\n", result); // Print the result
}

int main() {
    int fd, operand1, operand2, result; // File descriptor and operands
    char operation; // Operation character
    operation_func op = NULL; // Pointer to operation function

    fd = open(DEVICE_PATH, O_RDWR); // Open the device with read/write permissions
    if (fd < 0) { // Check if the device was opened successfully
        perror("Failed to open the device"); // Print error message if open fails
        return EXIT_FAILURE; // Return failure status
    }

    handle_input(&operation, &operand1, &operand2); // Get input from the user

    // Determine the operation function based on user input
    /*Open/Closed Principle (OCP)
    Principle:Software entities should be open for extension but closed for modification.
    To achieve this principle: New arithmetic operations can be added by defining new ioctl commands and extending the switch statement in device_ioctl. 
    This allows the module to be extended with new functionality without modifying existing code
 */
    switch (operation) {
        case 'a':
            op = add_operation; // Set function pointer to addition
            break;
        case 's':
            op = subtract_operation; // Set function pointer to subtraction
            break;
        case 'm':
            op = multiply_operation; // Set function pointer to multiplication
            break;
        case 'd':
            op = divide_operation; // Set function pointer to division
            break;
        case 'o':
            op = modulus_operation; // Set function pointer to modulus
            break;
        default:
            printf("Invalid operation\n"); // Print error for invalid operation
            close(fd); // Close the file descriptor
            return EXIT_FAILURE; // Return failure status
    }

    execute_operation(op, fd, operand1, operand2, &result); // Execute the selected operation
    display_result(result); // Display the result

    close(fd); // Close the file descriptor
    return EXIT_SUCCESS; // Return success status
}

