#include <stdio.h>

int main() {
	FILE *fp = fopen("data.txt","w");
	if (fp == NULL){
		printf("error in opening file !\n");
		return 1;
	}
	fprintf(fp ,"this is some sample text written to the file .\n");
	fclose(fp);

	printf("succesful wrote into the file\n");
	return 0;
}	

