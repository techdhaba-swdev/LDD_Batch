#include <stdio.h>

union MyUnion {
    char a;
    char b;
    char c;
    char d;
    char arr[4];
};

int main() {
    union MyUnion myUnion;

    myUnion.a = 'A';
    myUnion.b = 'B';
    myUnion.c = 'C';
    myUnion.d = 'D';

    printf("a: %c\n", myUnion.a);
    printf("b: %c\n", myUnion.b); 
    printf("c: %c\n", myUnion.c);
    printf("d: %c\n", myUnion.d); 

    myUnion.arr[0] = 'X';
    myUnion.arr[1] = 'Y';
    myUnion.arr[2] = 'Z';
    myUnion.arr[3] = 'W';
    
    printf("arr[0]: %c\n", myUnion.arr[0]); // Output: X
    printf("arr[1]: %c\n", myUnion.arr[1]); // Output: Y
    printf("arr[2]: %c\n", myUnion.arr[2]); // Output: Z
    printf("arr[3]: %c\n", myUnion.arr[3]); // Output: W

    
    printf("Size of union: %lu bytes\n", sizeof(union MyUnion)); // Output: 4 bytes

    return 0;
}

	

