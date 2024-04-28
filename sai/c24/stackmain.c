#include <stdio.h>
#include "stack.h"

int main() {
    push(5);
    push(10);
    printf("%d\n", pop()); // Should print 10
    printf("%d\n", pop()); // Should print 5
    printf("%d\n", pop()); // Should print -1 (stack is empty)
    return 0;
}
