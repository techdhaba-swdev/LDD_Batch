#include <stdio.h>

#include <string.h>

int main()
{

	
        char *strings[128];

        char string[256];

        char *p1, *p2;

        int nstrings;

        int found;

        int i, j;

        nstrings = 0;

        while (fgets(string, 256, stdin)){
		

                for (i = 0; i < nstrings; i++){
			
                        found = 1;

                        for (p1 = string, p2 = strings[i]; *p1 && *p2; p1++, p2++){
				

                                if (*p1 > *p2){
					found = 0;

                                        break;

                                }

                       }

                       if(found) 
			       break;

                 }

                 for (j = nstrings; j > i; j--)
			 strings[j] = strings[j-1];

                 strings[i] = strdup(string);

                 nstrings++;
		 if (nstrings >= 128) 
			 break;

        }

        for (i = 0; i < nstrings; i++)
		fprintf(stdout, "%s", strings[i]);

        return 0;

}
