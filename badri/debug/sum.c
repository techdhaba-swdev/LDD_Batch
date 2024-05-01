#include <stdio.h>
#include <time.h>

int main() {
	clock_t start = clock();
    int num1, num2, sum;
    
    // Prompt the user to enter the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    // Prompt the user to enter the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    // Calculate the sum
    sum = num1 + num2;
    
    // Display the sum
    printf("The sum is: %d\n", sum);
    clock_t end = clock();
    double time_taken = ((double)(start - end)) / CLOCKS_PER_SEC;
	 printf("time used: %f\n" , time_taken);
    return 0;
}
