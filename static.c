#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack {
	char*items;
	int top;
};
struct Stack* createStack(int size){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->items = (char*)malloc(size * sizeof(char));
	stack->top = -1;
}
int isEmpty(struct Stack* stack) {
	return stack->top == -1;
}
void push(struct Stack* stack,char item) {
	stack->items[++stack->top] = item;
}
char pop(struct Stack* stack) {
	if (isEmpty(stack))
		return '\0';
			return stack->items[stack->top--];
}
char* reverseString(const char* input) {
	int len = strlen(input);
	struct Stack* stack = createStack(len);
	for (int i = 0; i < len; i++) {
		push(stack, input[i]);
	}
	char* reversed = (char*)malloc((len + 1) * sizeof(char));
	reversed[len] = '\0';
	for (int i = 0; i < len; i++) {
		reversed[i] = pop(stack);
	}
	free(stack->items);
	free(stack);
	return reversed;
}
int main() {
	const char* input_string = "Hello, World!";
	char* reversed_output = reverseString(input_string);
	printf("Original String: %s\n", input_string);
	printf("Reversed String: %s\n", reversed_output);
	free(reversed_output);
	return 0;
}
