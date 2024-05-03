#include"tree.h"

// Structure for stack node
 struct StackNode {
    char data;
    struct StackNode* next;
} ;

// Structure for stack
 struct Stack{
    StackNode* top;
} ; 

// Create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Push an element onto the stack
void push(Stack* stack, char data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    char popped = stack->top->data;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

// Peek at the top element of the stack
char peek(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->top->data;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Check if a character is an operand
int isOperand(char ch) {
    return isalnum(ch);
}

// Get precedence of operators
int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

// Convert infix expression to postfix
char* infixToPostfix(char* expression) {
    Stack* stack = createStack();
    char* postfix = (char*)malloc((strlen(expression) + 1) * sizeof(char));
    int i, j;
    for (i = 0, j = 0; expression[i]; i++) {
        if (isOperand(expression[i])) {
            postfix[j++] = expression[i];
        } else if (expression[i] == '(') {
            push(stack, expression[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[j++] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return NULL; // Invalid expression
            else
                pop(stack); // Pop '('
        } else { // Operator
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)))
                postfix[j++] = pop(stack);
            push(stack, expression[i]);
        }
    }
    while (!isEmpty(stack))
        postfix[j++] = pop(stack);
    postfix[j] = '\0';
    return postfix;
}

// Evaluate postfix expression
int evaluatePostfix(char* postfix) {
    Stack* stack = createStack();
    int i;
    for (i = 0; postfix[i]; i++) {
        if (isOperand(postfix[i]))
            push(stack, postfix[i] - '0');
        else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch(postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(stack);
}


