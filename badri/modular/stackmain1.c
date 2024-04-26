#include <stdio.h>
#include "stackinit.h"
#include "stackpush.h"
#include "stackpop.h"
#include "stackempty.h"
#include "stackfull.h"

int main()
{
	stack_int();
	stack_push(10);
	int data = stack_pop();
	bool isEmpty = stack_is_empty();
	bool isFull = stack_is_full();
	return 0;
}

