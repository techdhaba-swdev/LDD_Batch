#include <stdio.h>
#include <string.h>
union name 
{
char a;
char b;
char c;
char d;
char arr[4];
};
int main()
{
union name stu;
stu.a = 'A';
printf("character of a %c\n",stu.a);
stu.b = 'B';
printf("character of b %c\n",stu.b);
stu.c = 'C';
printf("character of c %c\n",stu.c);
stu.d = 'D';
printf("character of d %c\n",stu.d);
printf("size of union %d\n",sizeof(stu));
}
