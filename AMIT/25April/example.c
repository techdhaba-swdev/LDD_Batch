#include<stdio.h>
#include"example.h"

int main() {
    int num1 = 10;
    int num2 = 20;

    // Function call with meaningful variable names
    int sum = add(num1, num2);
    int substraction= sub(num1, num2);

    // Clear and concise message
    print_message("The sum is: ");
    printf("%d\n", sum);

    print_message("The substraction is");
    printf("%d\n",substraction);

    return 0;  // Indicate successful program termination
}
