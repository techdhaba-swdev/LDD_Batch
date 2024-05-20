#include <stdio.h>
unsigned long long factorial(int n) {
  
    if (n == 0) {
        return 1;
    }
   
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    
    printf("Enter an integer: ");
    scanf("%d", &num);

        unsigned long long fact = factorial(num);
        printf("Factorial of %d is %llu\n", num, fact);
    printf("sizeof fact %d",sizeof(fact));
    
    return 0;
}
