#include<stdio.h>
#include<stdlib.h>
#include "string4.h"
int main(){ 
	char *strings[MAX_STRINGS] = {NULL};
	int nstrings = 0;
	readStrings(strings, &nstrings);
	sortStrings(strings, nstrings);
	printStrings(strings, nstrings);
	freeStrings(strings, nstrings);
	return 0;
}
