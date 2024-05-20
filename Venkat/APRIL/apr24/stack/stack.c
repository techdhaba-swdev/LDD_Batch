#include "stack.h"
#include <stdio.h>


void initialize(stack*s){
	s->top =-1;
}
int isEmpty(stack *s){
	return s->top ==-1;
}
int isFull(stack *s){
	return s->top ==MAX_SIZE -1;
}
