#include <stdio.h>
#include <string.h>
union myunion{
                char a,b,c,d;
                char arr[4];
        };
int main()
{
  union myunion t1;

  t1.a = 'a';
  printf("%c\n" ,t1.a);
  t1.b = 'b';
  printf("%c\n",t1.b);
  t1.c = 'c';
  printf("%c\n",t1.c);
  t1.d = 'd';
  printf("%c\n",t1.d);
  strcpy(t1.arr,"arr1");
  printf("%s\n",t1.arr);
}

