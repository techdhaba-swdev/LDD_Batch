#include "string4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readStrings(char *strings[], int *nstrings){
	char string[MAX_LENGTH + 1];
	while(fgets(string, sizeof(string), stdin)){
		string[strcspn(string, "\n")] = '\0';
		if(*nstrings < MAX_STRINGS -1){
			strings[*nstrings] = strdup(string);
			if(strings[*nstrings] == NULL){
				perror("strdup");
				exit(EXIT_FAILURE);
			}
			(*nstrings)++;
		}
		else{
			fprintf(stderr, "Maximum number of strings reached. Exiting...\n");
			break;
		}
	}
}
void sortStrings(char *strings[], int nstrings){
	for(int i=0;i<nstrings - 1;i++){
		for(int j=0; j< nstrings - i - 1;j++){
			if(strcmp(strings[j], strings[j+1]) > 0){
				char *temp = strings[j];
				strings[j] = strings[j+1];
				strings[j+1] = temp;
			}
		}
	}
}
void printStrings(char *strings[], int nstrings){
	for(int i=0;i<nstrings;i++){
		printf("%s\n", strings[i]);
	}
}
void freeStrings(char *strings[], int nstrings){
	for(int i=0;i<nstrings;i++){
		free(strings[i]);
	}
}

