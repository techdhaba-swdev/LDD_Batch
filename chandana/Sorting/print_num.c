#include <stdio.h>

void print_value(int n) {
        if(n < 0) {
                return;
        }
        else
        {
                printf("value is %d\n " ,n);
                print_value(n-1);
        }
}
int main() {
        print_value(10);
        return 0;
}               
