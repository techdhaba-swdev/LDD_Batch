#include<stdio.h>

void reverse(char *str){
	if(*str == '\0')
	{return;
	}
	reverse(str+1);
	printf("%c",*str);
}
int main(){
	char str[]="hello,world!";
	
printf("original string %s\n",str);
printf("reversed string ");
reverse(str);
printf("\n");
		return 0;
}
