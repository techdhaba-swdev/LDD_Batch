//source file input/output 
//it reads data from a file and writes it to another file securely

#include<stdio.h>
#define BUFFER_SIZE 100

int main(){
	FILE *sourceFile, *destinationFile;
	char buffer[BUFFER_SIZE];

	sourceFile = fopen("source.txt","r");
	destinationFile = fopen("destination.txt","w");

	if(sourceFile && destinationFile){
		while(fgets(buffer,BUFFER_SIZE,sourceFile) != NULL){
			fputs(buffer,destinationFile);
		}
		fclose(sourceFile);
		fclose(destinationFile);
		printf("File copied successfuylly.\n");
	}else{
		printf("Errors opening files.\n");
	}
	return 0;
}
