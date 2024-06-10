/* dry refers to dont repeat your self  here in the above program we are not repeating the funtion for doing multiple add operations we are using single function for performing many add operations*/

//example using dry principle
#include <stdio.h>

// Function to add two numbers
int add(int a, int b) {// in this program we are using function with code reusability easy to understand maintainability 
    return a + b;
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Calculate and print the sum
    int sum = add(num1, num2);
    printf("Sum: %d\n", sum);

    return 0;
}

//example without using dry principle
#include <stdio.h>

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Calculate and print the sum
    int sum = num1 + num2;//here in this program we are performing direct add operation in main function which violates dry principle 
    printf("Sum: %d\n", sum);

    return 0;
}
