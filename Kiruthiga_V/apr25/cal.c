#include <stdio.h>
#include <stdlib.h>
#include "cal.h"
int add(int x, int y) {
    return x + y;
}

// Function to subtract two numbers
int subtract(int x, int y) {
    return x - y;
}

// Function to multiply two numbers
int multiply(int x, int y) {
    return x * y;
}

// Function to divide two numbers
int divide(int x, int y) {
    if (y != 0) {
        return x / y;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

