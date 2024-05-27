#include<stdio.h>
int main(){
	char buffer[512];
	fgets(buffer,sizeof(buffer),stdin);
	printf("%sread from stdin\n",buffer);
	return 0;
}

