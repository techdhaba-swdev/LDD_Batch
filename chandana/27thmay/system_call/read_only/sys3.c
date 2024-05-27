#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void read(const char *file){
	FILE *f;
	char buffer[BUFFER_SIZE];

	//open the file to read
	f=fopen(file,"r");
	if(f ==NULL){
		perror("error opening file");
		exit(EXIT_FAILURE);
	}
	//To read and display each line
	while(fgets(buffer,BUFFER_SIZE,f) != NULL){
		printf("%s",buffer);
	}

	//close file
	if(fclose(f)!=0){
		perror("error closing file");
		exit(EXIT_FAILURE);
	}
}
int main(int argc,char *argv[]){
	if(argc !=2){
		fprintf(stderr,"file %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	read(argv[1]);
	return 0;
}
