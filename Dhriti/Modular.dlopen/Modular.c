#include<stdio.h>

#include "main.h"

int main(){
        int a,b,c,d;
	printf("Enter four numbers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);


	printf("Sum2:  %d\n", add_2(a,b));
	printf("Sum3:  %d\n", add_3(a,b,c));
	printf("Sum4:  %d\n", add_4(a,b,c,d));


	printf("Difference:  %d\n", sub_2(a,b));
	printf("Diff3:  %d\n", sub_3(a,b,c));
        printf("Diff4:  %d\n", sub_4(a,b,c,d));


         printf("Multiplication:  %d\n", mul_2(a,b));
         printf("Mul3:  %d\n", mul_3(a,b,c));
        printf("Mul4:  %d\n", mul_4(a,b,c,d));


         printf("Divison:  %d\n", div(a,b));
	 printf("Division3: %d\n", div(a,b,c));
        
	 return 0;
}
