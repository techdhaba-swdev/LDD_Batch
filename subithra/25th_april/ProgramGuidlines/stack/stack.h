#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

void stack_push(int data);
int stack_pop();
bool stack_is_empty();
bool stack_is_full();

#endif
