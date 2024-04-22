#include<stdio.h>
#include<string.h>
#define concat(x, y) x##y

int main()
{
	char str1[] = "Dhriti";
	char str2[] = "Ojha";

	char string[] =  concat(str1, str2);

	printf("The printed string is: %s\n", string);

	return 0;
}
