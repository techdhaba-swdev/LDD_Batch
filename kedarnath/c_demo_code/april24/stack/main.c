#include"main.h"
int main() {
    // Initialize the stack
    initialize();

    // Push some elements onto the stack
    push(10);
    push(20);
    push(30);

    // Pop elements and print them
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}

