#include<stdio.h>
#include<string.h>
void reverse(char* name ,int start,int end);
void reverse(char* name ,int start,int end)
{
char temp;
if (start == end)
{
return ;
}
*(name+start)=  *(name+start) + *(name+end);
*(name+end)= *(name+start) - *(name+end);
*(name+start)=  *(name+start) - *(name+end);
start++;
end--;
reverse(name,start,end);

}
int main()

{
char name[20]="mayur";
printf("%s\n",name);
reverse(name,0,(strlen(name)-1));
printf("%s\n",name);
return 0;
}
