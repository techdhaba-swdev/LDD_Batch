#include<stdio.h>
int main(){
	char username[10];
	printf("enter username: ");
	gets(username);
	printf("hi, %s\n", username);
	return 0;
}
