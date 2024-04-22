#include <stdio.h>

int factorial(int n) {
   
    if (n == 0) {
        return 1;
    }
    
    else {
        return n * factorial(n - 1);
    }
}
int main() {
    int input_num;
    
    printf("Enter number: ");
    scanf("%d", &input_num);
    
    printf("Factorial of %d = %d\n", input_num, factorial(input_num));
    
    return 0;
}