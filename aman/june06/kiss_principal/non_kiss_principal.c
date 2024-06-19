#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from the user with error checking
int readInteger(const char *prompt) {
    char input[256]; // Buffer to store user input
    int num; // Variable to store the converted integer
    while (1) { // Infinite loop until valid input is received
        printf("%s", prompt); // Print the prompt to the user
        if (fgets(input, sizeof(input), stdin) != NULL) { // Read input from user
            // Check if input is a valid number
            char *endptr; // Pointer to check the end of the conversion
            num = strtol(input, &endptr, 10); // Convert string to integer
            if (endptr != input && *endptr == '\n') { // Check if conversion was successful
                break; // Exit loop if input is valid
            }
        }
        printf("Invalid input. Please enter a valid integer.\n"); // Print error message for invalid input
    }
    return num; // Return the valid integer
}

// Function to add two integers
int addIntegers(int a, int b) {
    return a + b; // Return the sum of the two integers
}

// Function to print the result
void printResult(int num1, int num2, int sum) {
    printf("The sum of %d and %d is %d\n", num1, num2, sum); // Print the result
}

int main() {
    // Read integers from the user
    int num1 = readInteger("Enter the first integer: "); // Read first integer
    int num2 = readInteger("Enter the second integer: "); // Read second integer
    
    // Calculate the sum
    int sum = addIntegers(num1, num2); // Calculate the sum of the two integers
    
    // Print the result
    printResult(num1, num2, sum); // Print the sum

    return 0; // Return 0 to indicate successful execution
}
