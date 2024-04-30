#include <stdio.h>

int sum(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += i;
    }
    return result;
}

int main() {
    int num = 5;
    int result = sum(num);
    printf("Sum of first %d natural numbers is %d\n", num, result);
    return 0;
}
