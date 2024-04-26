#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "string.h"
void read_strings(char *strings[],char string[],int *nstrings){
	while(fgets(string,MAX_STRING_LENGTH,stdin)){
		int i;
		int found;
		char *p1, *p2;
		for(i=0;i<*nstrings;i++)
		{
			found=1;
			for(p1=string,p2=strings[i];*p1&&*p2;p1++,p2++){
				if(*p1>*p2){
					found=0;
					break;
				}
			}
			if(found)break;
		}
		for(int j=*nstrings;j>i;j--)
			strings[j]=strings[j-1];
		strings[i]=strdup(string);
		(*nstrings)++;
		if(*nstrings>=MAX_STRINGS)
			break;
	}
}
void sort_and_print(char *strings[], int nstrings){
	for(int i=0;i<nstrings;i++)
		fprintf(stdout,"%s",strings[i]);
}
