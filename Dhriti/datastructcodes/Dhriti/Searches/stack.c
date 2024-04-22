
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Stack{
	int top;
	float list[MAX];
};

void initialize(struct Stack* stack){
	stack->top = -1;//indicate empty stack
}

void push(struct Stack* stack, float value){
	if(stack->top ==MAX - 1) 
	{
		printf("Error: Stack Overflow\n");
		
	}
	stack->list[++stack->top] = value;// increments the top element and assign the value to the list array
}

float pop(struct Stack* stack){
        if(stack->top ==- 1){
                printf("Error: Stack Underflow\n");
               
        }
        return  stack->list[stack->top--]; // Returns the element at the top of the stack and decrements top
}

int isEmpty(struct Stack* stack){ // to check if the stack is empty
	return stack->top = -1; // it returns 1, if top is -1 indicating an empty stack
}
int main() {

	struct Stack stack;
	initialize(&stack);

  char op;
  double first, second;
  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &op);
  printf("Enter two operands: ");
  scanf("%lf %lf", &first, &second);

  switch (op) {
    case '+':
      printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
      break;
    case '-':
      printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
      break;
    case '*':
      printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
      break;
    case '/':
      printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
      break;
    // operator doesn't match any case constant
    default:
      printf("Error! operator is not correct");
  }
if(!isEmpty(&stack)){
	printf("Result: %2f\n", pop(&stack));
}

return 0;
}
