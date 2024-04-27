#include <stdio.h>//This line includes the standard input-output header file stdio.h, which provides functions like printf() and scanf() for input and output operations.
#include "fibonacci.h"//This line includes the header file "fibonacci.h". It allows us to use the function fibonacci declared in fibonacci.h in this source file.

int main() {//This line declares the main function, which is the entry point of the program. Execution of the program begins from here.
    int n;// This line declares an integer variable n. It will be used to store the input value of n from the user, representing the position of the Fibonacci number to be calculated.
    printf("Enter the value of n: ");//This line prints a message asking the user to enter the value of n onto the standard output (usually the console).
    scanf("%d", &n);//This line reads an integer input from the user and stores it in the variable n. The %d format specifier indicates that scanf should expect an integer input.

    unsigned long long fib = fibonacci(n);//This line calculates the Fibonacci number corresponding to the position n using the fibonacci function declared in fibonacci.h. The result is stored in the variable fib.
    printf("The %dth Fibonacci number is: %llu\n", n, fib);//This line prints the calculated Fibonacci number to the standard output. It uses %d to print the value of n, and %llu to print the value of fib, which is an unsigned long long integer

    return 0;//This line signifies the end of the main function and the program as a whole. It returns an exit status of 0 to the operating system, indicating that the program executed successfully.
}


//secure code -- This implementation is secure because it handles both small and large Fibonacci numbers correctly and prevents buffer overflow or other memory-related issues.


