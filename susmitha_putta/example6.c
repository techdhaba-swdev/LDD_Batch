#include <stdio.h>

#include <time.h>
 
int main() {

    // Start the clock

    clock_t start = clock();
 
    // Code whose time complexity you want to measure

    // For example, let's calculate the sum of first 1000 numbers

    int sum = 0;

    for (int i = 1; i <= 1000; i++) {

        sum += i;

    }
} 
