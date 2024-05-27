#include<stdio.h>
#include<stdlib.h>


#define BUFF_SIZE 100

int main() {
	FILE *file;
	char buffer[BUFF_SIZE];       //bUFFRE for reading lines from the source file

	//Open the file for read only
    
	file = fopen("src.txt", "r");
	if(file == NULL) {
		perror("File is empty failed to open the file");
		return EXIT_FAILURE;
	}

	//Read & display each line from the source file
        while(fgets(buffer, BUFF_SIZE, file)) { //fgets: reads each line from the buffer

			printf("%s", buffer); //Print the content from buffer
			}

			fclose(file);

			return 0;
}
