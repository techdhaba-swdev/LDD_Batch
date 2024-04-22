#include<stdio.h>

void calculator()
{
	int a,b,n;
	printf("Enter two number:\n");
	scanf("%d%d",&a,&b);
	printf("Enter your choice:\n \tAddition=1\n\tSustraction=2\n\tMultiplication=3\n\tDivision=4\n");
	scanf("%d",&n);

	switch(n)
	{
		case 1:

	         printf("Addition is=%d\n",a+b);
		 break;
		case 2:

           	printf("Substraction is=%d\n",a-b);
		break;

		case 3:
		printf("multiplication is=%d\n",a*b);
		break;

		case 4:
		printf("Division is=%d\n",a/b);
		break;

		default:
		printf("Please enter correct choice:\n");
	}
}
