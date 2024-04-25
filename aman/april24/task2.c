#include<stdio.h>
int main(){
	char password[10];
	printf("enter your password: ");
	gets(password);
	printf("you entered: %s\n", password);
	return 0;
}
