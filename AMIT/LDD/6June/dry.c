#include <stdio.h>

void printTable(int number) {
    for (int i = 1; i <= 10; ++i) {
        printf("%d * %d = %d\n", number, i, number * i);
    }
}

int main() {
    printTable(7);
    return 0;
}

