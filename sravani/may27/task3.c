#include<stdio.h>

int main(){
	 char data;
	 printf("enter text(ctrl+D)end\n");
	 while(data=getchar()!=EOF){
		 putchar(data);
	 }
	 printf("end of line\n");
	 return 0;
}
