#include <stdio.h>          // For standard input/output functions
#include <stdlib.h>         // For standard library functions, including EXIT_FAILURE and EXIT_SUCCESS
#include <fcntl.h>          // For file control options (open function)
#include <unistd.h>         // For close function
#include <sys/ioctl.h>      // For ioctl function

#define DEVICE_PATH "/dev/my_calculator_device" // Path to the calculator device
#define IOCTL_MAGIC 'c'                         // Magic number for ioctl
#define IOCTL_CALC _IOWR(IOCTL_MAGIC, 1, struct calc_data) // ioctl command definition

// Define a structure to hold the calculation data
struct calc_data {
    int num1;      // First operand
    int num2;      // Second operand
    char operation; // Operation to perform (+, -, *, /)
    int result;    // Result of the operation
};

int main() {
    int fd; // File descriptor for the device
    struct calc_data data; // Structure to hold user input and result

    // Open the device for reading and writing
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) { // Check if the device failed to open
        perror("Failed to open the device"); // Print error message
        return EXIT_FAILURE; // Return failure status
    }

    // Prompt user for input and read the values
    printf("Enter first number: ");
    scanf("%d", &data.num1); // Read first number
    printf("Enter second number: ");
    scanf("%d", &data.num2); // Read second number
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &data.operation); // Read operation (note the space to handle newline)

    // Perform ioctl to send data to the kernel module and get the result
    if (ioctl(fd, IOCTL_CALC, &data) < 0) { // Check if ioctl failed
        perror("Failed to execute ioctl"); // Print error message
        close(fd); // Close the device
        return EXIT_FAILURE; // Return failure status
    }

    // Print the result of the calculation
    printf("Result: %d %c %d = %d\n", data.num1, data.operation, data.num2, data.result);

    close(fd); // Close the device
    return EXIT_SUCCESS; // Return success status
}
