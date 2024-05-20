#include<stdio.h>
union Union{
char a;
char b;
char c;
char d;
char arr[4];
};

int main(){
union Union u;
u.a='A';
u.b='B';
u.c='C';
u.d='D';

u.arr[0]='E';
u.arr[1]='F';
u.arr[2]='G';
u.arr[3]='H';

printf("value of a: %c\n",u.a);
printf("value of b: %c\n",u.b);
printf("value of c: %c\n",u.c);
printf("value of d: %c\n",u.d);

printf("value of arr[0]: %c\n",u.arr[0]);
printf("value of arr[0]: %c\n",u.arr[1]);
printf("value of arr[0]: %c\n",u.arr[2]);
printf("value of arr[0]: %c\n",u.arr[3]);

return 0;
}
