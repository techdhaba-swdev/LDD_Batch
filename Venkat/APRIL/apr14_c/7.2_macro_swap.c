#define swap(a,b) a=a+b ,b=a-b,a=a-b 
#include <stdio.h>
int main()
{
    int a =5,b=10;
    swap(a,b);
    printf("after swap %d , %d\n",a,b);
}