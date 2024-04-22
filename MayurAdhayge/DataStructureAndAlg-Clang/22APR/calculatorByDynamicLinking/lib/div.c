#include <stdio.h>
float div(int num1, int num2)
{
	if(num2==0)
	{
	 printf("zero division not allowed");
	 return 0;
	}

return(num1/(float) num2);

}

