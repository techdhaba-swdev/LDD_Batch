#include<stdio.h>
#include<string.h>
int main(){
	char file[10];
	char source[20] = "The length of the string.";
	strcpy(file, source);
	printf("File: %s\n", file);

	return 0;
}

//Here, the length of source string exceeds the capacity of file, leading to overflow.
