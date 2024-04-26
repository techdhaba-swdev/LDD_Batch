#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define MAX_SIZE 5 //define the maximun elements

static int stack[MAX_SIZE]; //initalize stack array
static int top = -1;        //initialise top as -1

void stack_push(int data) { //implementing push function
    if (stack_is_full()) {
        printf("Stack overflow\n"); //print if stack is overflow
        return;
    }
    stack[++top] = data;
}

int stack_pop() { //implementing pop function
    if (stack_is_empty()) {
        printf("Stack underflow\n"); //print if stack is underflow
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

bool stack_is_empty() {//implementing stack empty function
    return top == -1;
}

bool stack_is_full() { ////implementing stack full function
    return top == MAX_SIZE - 1;
}


