#include <stdio.h>

void strCopy(char dest[], char src[]){
	int i=0;
	while(src[i] !='\0'){
		dest[i]=src[i];
		i++;
	}
	dest[i]='\0';

}
int main() {
	char src[]="hello world";
	char dest[100];

	strCopy(dest,src);

	printf("Source string %s\n",src);
	printf("Copied string %s\n",dest);

	return 0;
}
