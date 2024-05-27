#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
	char buffer[BUFFER_SIZE];

	//read from std input and display on std output
	while(fgets(buffer,BUFFER_SIZE,stdin)!=NULL){
		printf("%s",buffer);
	}
	return 0;
}
