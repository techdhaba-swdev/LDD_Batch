#include<stdio.h>
int main()
{
	int var1,var2,temp;
	printf("Enter two integers\n");
	scanf("%d%d",&var1,&var2);
	printf("Before SwappingFirst variable = %d\nSecond variable = %d\n",var1,var2);
	temp = var1;
	var1 =var2;
	var2 =temp;
	printf("After SwappingFirst variable = %d\nSecond variable = %d\n",var1,var2);
	return 0;
}

