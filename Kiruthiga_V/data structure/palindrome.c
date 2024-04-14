#include <stdio.h>
#include <string.h>
#include <ctype.h>
int is_palindrome(const char *s)
{
int length = strlen(s);
int i,j;
char lowercase[length + 1];
for (i = 0; i < length; i++)
{
lowercase[i] = tolower(s[i]);
}
lowercase[length] = '\0';
for(i = 0, j = length -1; i < j; i++, j--)
{
while (!isalnum(lowercase[i]) && i < j)
{
i++;
}
while (!isalnum(lowercase[j]) && i < j)
{
j--;
}
if (lowercase[i] != lowercase[j])
{
return 0;
}
}
return 1;
}
int main ()
{
const char *string = "A man, a plan, a canal, Panama";
if(is_palindrome(string))
{
printf("the string is a palindrome.\n");
}
else
{
printf("the string is not a palindrome.\n");
}
return 0;
}
