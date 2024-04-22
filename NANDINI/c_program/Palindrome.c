#include<stdio.h>

main()
{
	int n, r, sum=0, temp;
	printf("Enter n");
	scanf("%d",&n);
	temp=n;
	while(n != 0)
	{
		r = n%10;
		sum = sum * 10 + r;
		n=n/10;
	}
	if(temp == sum)
		printf("palindrome");

	else
		printf("not palindrome");
	getch();
}

