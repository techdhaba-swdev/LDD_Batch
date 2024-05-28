#include <stdio.h>
void my_strcpy (char *dest, const char *src)
{
while (*src != '0')
{
*dest = *src;
src++;
dest ++;
}
*dest = '\0';
}
int main()
{
const char *src = "Hello, world!";
char dest[20];
my_strcpy(dest,src);
printf("copied string: %s\n",dest);
return 0;
}
