//uninitialised variable usage

#include <stdio.h>

int main() {
    int x;
    printf("%d\n", x); // Using uninitialized variable
    return 0;
}

// #include <stdio.h>
// int main() {
//     int x=5;
//     printf("%d\n", x); // Using uninitialized variable
//     return 0;
// }
