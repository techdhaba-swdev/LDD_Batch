#include <stdio.h>
#include<string.h>

#define concat(desert,src) {strcat(desert,src)}

int main()
{
	char str1[100] = "Sai";
	char str2[] = "Kiran";
         
	char name[100]= concat(str1,str2);
	

	printf("  String Concation = %s\n",name);
}	
