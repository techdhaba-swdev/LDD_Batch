#include <stdio.h>
#include "cal.h"
int main(){
int num1, num2;
char choice;
printf("enter operator(+,-,*,/)");
scanf("%c",&choice);
printf("enter first number");
scanf("%d", &num1);
printf("enter second number");
scanf("%d", &num2);
switch(choice){
case '+':
      printf("result:%d\n",add(num1, num2));
      break;
case '-':
      printf("result:%d\n",subtract(num1, num2));
      break;
case '*':
      printf("result:%d\n",multiply(num1, num2));
      break;
case '/':
      if(num2 !=0)
      printf("result:%d\n",divide(num1, num2));
      else
      printf("no divide by zero plz");
      break;
      default:
      printf("error invalid operator");
      }
      return 0;
 }
