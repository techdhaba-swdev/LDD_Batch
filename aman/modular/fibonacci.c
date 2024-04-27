#include "fibonacci.h" //This line includes the header file "fibonacci.h" in the source file. This allows the functions and types declared in fibonacci.h to be used in this source file.
unsigned long long fibonacci(int n) {//This line defines the function fibonacci. It specifies that the function returns an unsigned long long integer (unsigned long long) and takes an integer n as its argument. The function calculates and returns the nth Fibonacci number.
    if (n <= 1)//This line checks if the input n is less than or equal to 1, which are the base cases of the Fibonacci sequence (fib(0) = 0 and fib(1) = 1).
        return n;//If n is less than or equal to 1, the function returns n itself because in this case, the Fibonacci number is equal to n

    unsigned long long a = 0, b = 1;//This line declares and initializes two variables a and b as unsigned long long integers. These variables are used to store the Fibonacci numbers for the current and next positions in the sequence, respectively.
    for (int i = 2; i <= n; i++) {//his line starts a loop that iterates from i = 2 to n, inclusive. It calculates Fibonacci numbers starting from the 3rd position (i = 2) because the first two positions (i = 0 and i = 1) have already been accounted for in the base cases.
        unsigned long long temp = a + b;//this line calculates the Fibonacci number for the current position (i) by adding the Fibonacci numbers stored in variables a and b
        a = b;//These lines update the values of variables a and b to prepare for the next iteration. a is updated to the Fibonacci number for the previous position (i - 1), and b is updated to the Fibonacci number for the current position (i).
        b = temp;
    }
    return b;//This line returns the Fibonacci number calculated for the nth position, which is stored in variable b
}

