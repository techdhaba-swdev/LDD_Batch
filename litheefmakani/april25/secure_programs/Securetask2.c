//safe string handling
//copies a string from one variable to another without causing buffer overflow

#include<stdio.h>
#include<string.h>

int main(){
	char source[] = "hello litheef";

	char destination[20];

	strncpy(destination,source, sizeof(destination) -1);
	destination[sizeof(destination)-1] = '\0';//Ensure null termination
	
	printf("copied string : %s\n",destination);
	return 0;
}




