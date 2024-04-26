#include<stdio.h>
#include<string.h>
int      main(){
	char buffer[5];
	strcpy(buffer,"this is buffer overflow");
	printf("%s\n",buffer);
	return 0;
}
