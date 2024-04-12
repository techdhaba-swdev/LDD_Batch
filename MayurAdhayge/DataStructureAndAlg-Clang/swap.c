#include<stdio.h>
void main()
{
 int a=10,b=54;
 printf("befor swap the value a=%d and b=%d .",a,b);
 a=a^b;
 b=a^b;
 a=a^b;
 printf("after swap the value is a=%d and b=%d .",a,b);
}
