#include <stdio.h>
#include <string.h>
#define CONCAT(dest, src) strcat(dest, src)
int main()
{
char str1[20] = "Good";
char str2[] =  "evening!";
CONCAT (str1, str2);
printf("concatenated string :%s\n",str1);
return 0;
}

