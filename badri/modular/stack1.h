#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_SIZE 100

extern int stack_data[MAX_SIZE];
extern int stack_top;

void stack_init();
void stack_push(int data);
int stack_pop();
bool stack_is_empty();
bool stack_is_full();

#endif
