#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool isPal(char *a)
{
int start=0, end=strlen(a)-1;
while(start<=end)
{
if(a[start]!=a[end]){
return 0;
}
start++;
end--;
}
return 1;
}
int main(){
char a[]="madam";
if(isPal(a)){
printf("%s is a palindrome\n",a);
}
else
{
printf("%s is not a palindrome\n",a);
}
return 0;
}
