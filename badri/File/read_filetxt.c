#include <stdio.h>
#include <stdlib.h>

int main()
{
	char buffer[1020];
	FILE *fp = fopen("std.txt" , "rt");
	if (fp == NULL)
	{
		printf( "error in opening file\n" );
		return -1;
	}
	
	 while(fgets(buffer , sizeof(buffer) , fp) > 0)
	{
		printf("%s" , buffer);
	}
	
	fclose(fp);
	return 0;
}

