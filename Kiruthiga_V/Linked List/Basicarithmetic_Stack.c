#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

typedef struct StackNode StackNode;

// Function to create a new stack node
StackNode* createNode(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(StackNode* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(StackNode** top_ref, int data) {
    StackNode* newNode = createNode(data);
    newNode->next = *top_ref;
    *top_ref = newNode;
}

// Function to pop an element from the stack
int pop(StackNode** top_ref) {
    if (isEmpty(*top_ref)) {
        printf("Stack underflow.\n");
        exit(1);
    }
    StackNode* temp = *top_ref;
    *top_ref = (*top_ref)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to return the top element of the stack without popping it
int peek(StackNode* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        exit(1);
    }
    return top->data;
}

// Function to evaluate the expression using the stack
int evaluateExpression(char* expression) {
    StackNode* operand_stack = NULL;
    StackNode* operator_stack = NULL;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == ' ') {
            continue;
        } else if (expression[i] >= '0' && expression[i] <= '9') {
            int num = 0;
            while (expression[i] >= '0' && expression[i] <= '9') {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            push(&operand_stack, num);
            i--;
        } else if (expression[i] == '(') {
            push(&operator_stack, expression[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty(operator_stack) && peek(operator_stack) != '(') {
                int operand2 = pop(&operand_stack);
                int operand1 = pop(&operand_stack);
                char op = pop(&operator_stack);
                switch(op) {
                    case '+':
                        push(&operand_stack, operand1 + operand2);
                        break;
                    case '-':
                        push(&operand_stack, operand1 - operand2);
                        break;
                    case '*':
                        push(&operand_stack, operand1 * operand2);
                        break;
                    case '/':
                        push(&operand_stack, operand1 / operand2);
                        break;
                }
            }
            if (!isEmpty(operator_stack)) {
                pop(&operator_stack); // Pop '('
            }
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!isEmpty(operator_stack) && peek(operator_stack) != '(' &&
                   ((expression[i] == '*' || expression[i] == '/') || (peek(operator_stack) == '+' || peek(operator_stack) == '-'))) {
                int operand2 = pop(&operand_stack);
                int operand1 = pop(&operand_stack);
                char op = pop(&operator_stack);
                switch(op) {
                    case '+':
                        push(&operand_stack, operand1 + operand2);
                        break;
                    case '-':
                        push(&operand_stack, operand1 - operand2);
                        break;
                    case '*':
                        push(&operand_stack, operand1 * operand2);
                        break;
                    case '/':
                        push(&operand_stack, operand1 / operand2);
                        break;
                }
            }
            push(&operator_stack, expression[i]);
        }
    }

    while (!isEmpty(operator_stack)) {
        int operand2 = pop(&operand_stack);
        int operand1 = pop(&operand_stack);
        char op = pop(&operator_stack);
        switch(op) {
            case '+':
                push(&operand_stack, operand1 + operand2);
                break;
            case '-':
                push(&operand_stack, operand1 - operand2);
                break;
            case '*':
                push(&operand_stack, operand1 * operand2);
                break;
            case '/':
                push(&operand_stack, operand1 / operand2);
                break;
        }
    }

    return pop(&operand_stack);
}

// Main function to test the calculator
int main() {
    char expression[] = "((2 + 3) * 5) - (6 / 2)";
    printf("Expression: %s\n", expression);
    printf("Result: %d\n", evaluateExpression(expression));
    return 0;
}



