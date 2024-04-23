#include <stdio.h>
#include <stdlib.h>

int main() {
	//open the file "data.txt" for reading(r)
	FILE *fp = fopen("data.txt","r");

	if(fp==NULL){
		printf("ERROR OPEING FILE|N");
		return 1;
	}

	//read and print 
	char ch;
	while((ch=fgetc(fp))!=EOF) {
		printf("%c",ch);
	}

	fclose(fp);
	return 0;
}
