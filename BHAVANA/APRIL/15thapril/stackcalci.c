#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

int evaluateExpression(char* exp) {
    struct Stack* stack = createStack(strlen(exp));
    int i;
    
    for (i = 0; exp[i]; ++i) {
        if (isdigit(exp[i]))
		int num = 0;
	while (isdigit(exp[i])) {
		num = num * 10 + (exp[i] - '0');
		i++;
	}
	push(stack, num);
         }
    else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') 
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]) {
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2 / val1); break;
            }
        }
    }
    return pop(stack);
}

int main() {
    char exp[100];
    printf("Enter the expression: ");
    scanf("%[^\n]", exp);
    printf("Result: %d\n", evaluateExpression(exp));
    return 0;
}



