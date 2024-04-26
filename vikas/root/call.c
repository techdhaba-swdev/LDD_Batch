#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void rev_string(char *s,int i,int j)
{
        if(i>=j)
                return;
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        rev_string(s,i+1,j+1);
}
void main( )
{
        char str[100];
        printf("enter string:");
        fgets(str,sizeof(str),stdin);
        size_t len=strlen(str);
        if(str[len-1]=='\n')
        {
                str[len-1]='\0';
        }
        len=strlen(str);
        rev_string(str,0,len-1);
        printf("reversed string:%s\n",str);

}

