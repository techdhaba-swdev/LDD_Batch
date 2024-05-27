#include<stdio.h>
int main(){
	char buffer[256];
	fgets(buffer,sizeof(buffer), stdin);
	printf("%s",buffer);
	return 0;
}
