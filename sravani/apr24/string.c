#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "string.h"
void sort_strings(){
	char *strings[MAX_STRINGS];
	char string[MAX_STRING_LENGTH];
	int nstrings=0;
	read_strings(strings,string,&nstrings);
	sort_and_print(strings,nstrings);
	for(int i=0;i<nstrings;i++)
	{
		free(strings[i]);
	}
}


