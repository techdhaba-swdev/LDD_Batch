#include<stdio.h>
#define con(s1,s2) (s1##s2)
int main()
{
char a[]="may";
char b[]="ur";
printf("%s",con(a,b));
return 0;
}
