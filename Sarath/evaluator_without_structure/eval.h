#ifndef EVAL_H_
#define EVAL_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

//char stack[MAX];
//int stack2[MAX];
//char infix[MAX];
//char postfix[MAX];
///int top=-1;
void intopost(void);
void push(int val);
void push1(int val);
int pop(void);
int pop1();
int isEmpty();
void print(void);
int precedence(int symbol);
int post();

#endif
