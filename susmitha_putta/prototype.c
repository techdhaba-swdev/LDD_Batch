#include <stdio.h>  // Standard Input/Output library

// Function prototypes (optional for small projects)
int add(int x, int y);
void print_message(const char *message);

int main() {
    int num1 = 10;
    int num2 = 20;

    // Function call with meaningful variable names
    int sum = add(num1, num2);

    // Clear and concise message
    print_message("The sum is: ");
    printf("%d\n", sum);

    return 0;  // Indicate successful program termination
}

// Function implementation with comments
int add(int x, int y) {
    int result = x + y;
    return result;  // Return the calculated sum
}
void print_message(const char *message) {
    printf("%s", message);
}
