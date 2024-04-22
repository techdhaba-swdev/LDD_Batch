#include "add.h"
#include<stdio.h>
int main(){
int num1, num2, sum;
printf("enter number first");
scanf("%d", &num1);
printf("enter number second");
scanf("%d", &num2);
sum = add(num1, num2);
printf("sum=%d\n",sum);
return 0;
}
