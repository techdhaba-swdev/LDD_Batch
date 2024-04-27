#include<stdio.h>
#include "add.h"
#include "message.h"

int main() {
    int x = 10;
    int y = 20;

    int sum = add(x, y);

    print_message("the sum is: ");
    printf("%d\n", sum);

    return 0;
}
