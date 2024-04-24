#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100


void initialize();
bool isFull();
bool isEmpty();
int pop();
void push(int data);

#endif
