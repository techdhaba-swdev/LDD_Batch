#include <stdio.h>
int main()
{
    union exp{
    char a;
    char b;
    char c;
    char d;
    char arr[4];
};

int main() {
    union Example ex;
    ex.a = 'A';
   
    printf("a: %c\n", ex.a);
    printf("b: %c\n", ex.b);
    printf("c: %c\n", ex.c);
    printf("d: %c\n", ex.d);
    printf("arr[0]: %c\n", ex.arr[0]);
    printf("arr[1]: %c\n", ex.arr[1]);
    printf("arr[2]: %c\n", ex.arr[2]);
    printf("arr[3]: %c\n", ex.arr[3]);
   
    return 0;
}
