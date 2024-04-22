#include<stdio.h>
#include<string.h>
#define concat(str1,str2) strcat(str1,str2)
int main()
{
	char str1[10] = "NANDINI";
	char str2[10] = "POTNURU";
	concat(str1,str2);;
	printf("concatinated string: %s\n", str1);
	return 0;
}
