#include<stdio.h>

int main()
{
char username[10];//declares array for holding 10 characters and the size is 10bytes
printf("enter username");//prints the message
gets(username);//stores the message in username array till 10 characters,if its more than 10 it will overflow
return 0;
}

