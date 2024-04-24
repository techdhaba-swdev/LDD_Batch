#include"string.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void stringread(char *strings[], int *nstrings)
{
	char string[MAX_LEN + 1];
	while(fgets(string, sizeof(string), stdin))
	{
		string[strcspn(string, "\n")] ='\0';
	       if(*nstrings < MAX_SIZE - 1)
	       {
	strings[*nstrings] = strdup(string);

        if(strings[*nstrings] == NULL)
             {

               perror("strdup");
             }
	
              (*nstrings)++;
              }

             else
                 {
	fprintf(stderr, "Maximum number of string.\n");
	break;
                 }

      }
}
void stringsort(char *strings[],int nstrings)
{
	for(int i=0; i < nstrings-1; i++)
	{
		for(int j=0; j < nstrings-i-1;j++)
		{
			if(strcmp(strings[j], strings[j+1]) > 0)
			{
				char *temp = strings[j];
				strings[j] = strings[j+1];
				strings[j+1] = temp;
			}
		}
		
	}
}

void stringprint(char *strings[], int nstrings)
{
	for(int i = 0; i<nstrings; i++)
	{
		printf("%s\n", strings[i]);
	}
}


