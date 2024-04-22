#include<stdio.h>
#include<string.h>
#define CONCAT(str1,str2) strcat(str1,str2)
int main(){
	char str1[20]="bts ";
	char str2[20] = "army";
	CONCAT(str1,str2);;
	printf("Concatenated string :%s\n",str1);
	return 0;
}
