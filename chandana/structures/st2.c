#include <stdio.h>
#include <string.h>

int isPalindrome(char* str) {
	int length = strlen(str);
	for(int i=0;i<length/2;i++){
		if(str[i]!=str[length-i-1]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	char str[100];
	printf("Rnter a string ");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';

	if(isPalindrome(str)) {
		printf("The string is a palindrome \n");
	}
	else {
		printf("the string is not palindrome \n");
	}
	return 0;
}
