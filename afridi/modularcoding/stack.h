#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void stack_init(Stack *s);
void stack_push(Stack *s, int data);
int stack_pop(Stack *s);
bool stack_is_empty(Stack *s);
bool stack_is_full(Stack *s);

#endif


