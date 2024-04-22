#include<stdio.h>
#include<string.h>
bool isPal(char *a)
{
int start=0, end=strlen(a)-1;
while(start<end)
{
if(str[sttart]!=a[end]0{
return false;
}
start++;
end--;
}
return true;
}
int main(){
char a[]="madam";
if(isPal(a)){
printf("%s is a palindrome",a);
else
{
printf("%s is not a palindrome",a);
}
return 0;
}
