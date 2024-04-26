#include "functions.h"
#include<stdio.h>
int main(){
        int num1 = 10;
        int num2 = 20;
        int sum = add(num1, num2);
        print_message("The sum is: ");
        printf("%d\n", sum);
        return 0;
}
