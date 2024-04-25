//Format string Vulnerability 

#include <stdio.h>

int main() {
	char input[100];
	printf("ENTER YOUR NAME: ");
	gets(input);//unsafe can lead to buffer overflow
	printf(input);
	return 0;
}
