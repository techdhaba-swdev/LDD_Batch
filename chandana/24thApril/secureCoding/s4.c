#include <stdio.h>

int main() {
char username[10];//Only 10 bytes alloacted
printf("Enter Username : ");
gets(username);//unbounded input can overflow the buffer
printf("hello,%s!\n",username);
return 0;
}
//code that user the username variable could be comprismed
//Buffer overflow :
//username array is declared with 10 bytes but the gets function to read input to username
