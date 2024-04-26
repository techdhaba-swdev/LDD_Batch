#include<stdio.h>
#include<string.h>
int main(){
	char source[]="hello baby girl  welcome to new  world";
	char destination[3];
	strcpy(destination,source);


	printf("%s\n",destination);
	return 0;
}
