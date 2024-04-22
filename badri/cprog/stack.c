
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100


struct Stack {
    int top;
    unsigned capacity;
    char* array;
};


struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}


char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}


void reverseString(char* str) {
    int length = strlen(str);
    struct Stack* stack = createStack(length);

   
    for (int i = 0; i < length; i++) {
        push(stack, str[i]);
    }

   
    for (int i = 0; i < length; i++) {
        str[i] = pop(stack);
    }
}


int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; //remove a new line characyter

    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
