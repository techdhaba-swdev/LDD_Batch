#include <stdio.h>
#include "stack3main.h"
int main() {
        
        push(10);
        push(20);
        push(30);
        printf("Popped value: %d\n", pop());
        printf("Popped value: %d\n", pop());

        return 0;
}
