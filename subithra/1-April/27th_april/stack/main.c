#include <stdio.h>
#include "main.h"

int main() {
  //pushing the elements
    stack_push(10);
    stack_push(20);
    stack_push(30);
    stack_push(40);
    
    //popping the elemnts
    printf("Popped element: %d\n", stack_pop());
    printf("Popped element: %d\n", stack_pop());

    return 0;
}


