//password inputprogram
//that prompts the user for a password without echoing it to the terminal

#include<stdio.h>
#include<unistd.h>
int main(void){
	char *password;
	password = getpass("Enter password: ");
	printf("you entered password : %s\n",password);
	return 0;
}

