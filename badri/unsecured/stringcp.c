#include <stdio.h>
#include <string.h>
int main()
{
	char buffer[10];
	strcpy(buffer , "this is a longer string than the buffer can hold");
	printf("%s\n",buffer);
	return 0;
}
