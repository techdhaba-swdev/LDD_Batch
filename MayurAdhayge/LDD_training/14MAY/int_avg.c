#include<stdio.h> // this header is include to use the scanf and printf
void main()// here is the main function is entry point
{
	int num1,num2;//define the two variable for holding the two integer value
	int sum;//define the sum variable for sum two number
	float avg;//defining the avg variable for average of two number and sum for sum of two number
	printf("\nEnter the first number:-");//that the prompt shown for entering the first value
	scanf("%d",&num1);//first number get in the variable num1
        printf("\nEnter the second number:-");//console prompt for the getting the second value
	scanf("%d",&num2);//second number get in variable num2
	sum=num1+num2;//sum of two number happend here
	avg=sum/2.0;//avrage of two number happen over here
	printf("sum=%d \t avg=%.2f",sum,avg);//printing the output here

}
