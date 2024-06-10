#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For isdigit()

// Define the TreeNode structure (as shown earlier)
struct TreeNode {
    int isOperator; // 1 if operator, 0 if operand
    union {
        char operatorSymbol; // +, -, *, /
        int operandValue;    // Integer value
    } data;
    struct TreeNode* left;
    struct TreeNode* right;
};
//create new binary tree node
struct TreeNode* createNode(int isOperator, char operatorSymbol, int operandValue) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->isOperator = isOperator;
    if (isOperator) {
        newNode->data.operatorSymbol = operatorSymbol;
    } else {
        newNode->data.operandValue = operandValue;
    }
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Helper function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
// Stack structure for operands and intermediate results
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Create a new stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    stack->array[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}
// Helper function to get precedence of an operator
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0; // Not an operator
    }
}

// Convert infix expression to postfix
void infixToPostfix(const char* infix, char* postfix) {
    int len = strlen(infix);
    char stack[100]; // Assume infix won't exceed 100 characters
    int top = -1; // Stack top

    int j = 0; // Index for postfix expression

    for (int i = 0; i < len; ++i) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[j++] = ch; // Operand, add to postfix
        } else if (isOperator(ch)) {
            while (top >= 0 && isOperator(stack[top]) &&
                   getPrecedence(stack[top]) >= getPrecedence(ch)) {
                postfix[j++] = stack[top--]; // Pop higher precedence operators
            }
            stack[++top] = ch; // Push current operator onto stack
        } else if (ch == '(') {
            stack[++top] = ch; // Push opening parenthesis
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--]; // Pop until matching '('
            }
            --top; // Discard '('
        }
    }

    // Pop remaining operators from stack
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

//Build the binary tree from postfix expression
struct TreeNode* buildTreeFromPostfix(const char* postfix) {
    struct TreeNode* stack[100]; // Assume postfix expression won't exceed 100 tokens
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; ++i) {
        if (isdigit(postfix[i])) {
            // Operand: Create a new node
            int operandValue = postfix[i] - '0'; // Convert char to int
            stack[++top] = createNode(0, '\0', operandValue);
        } else if (isOperator(postfix[i])) {
            // Operator: Pop top two nodes, create a new node, and push back
            struct TreeNode* rightChild = stack[top--];
            struct TreeNode* leftChild = stack[top--];
            stack[++top] = createNode(1, postfix[i], 0);
            stack[top]->left = leftChild;
            stack[top]->right = rightChild;
        }
    }

    return stack[top]; // Root of the binary tree
}

// In-order traversal and expression evaluation
int evaluateExpression(struct TreeNode* root) {
    if (root == NULL) {
        return 0; // Empty tree
    }

    struct Stack* stack = createStack(100); // Adjust capacity as needed

    struct TreeNode* current = root;
    while (current != NULL || stack->top != -1) {
        // Traverse to the leftmost node
        while (current != NULL) {
            if (!current->isOperator) {
                // Operand: Push its value onto the stack
                push(stack, current->data.operandValue);
            } else {
                // Operator: Pop top two values, apply the operator, and push result
                int operand2 = pop(stack);
                int operand1 = pop(stack);
                switch (current->data.operatorSymbol) {
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
                        push(stack, operand1 / operand2);
                        break;
                }
            }
            current = current->left;
        }

        // Move to the right child or backtrack
        if (stack->top != -1) {
            current = pop(stack);
            current = current->right;
        }
    }

    // Result will be at the top of the stack
    int result = pop(stack);

    // Clean up (free memory)
    free(stack->array);
    free(stack);

    return result;
}


int main() {
     char infixExpression[100];
    printf("Enter an infix expression: ");
    scanf("%s", infixExpression);

    char postfixExpression[100];
    infixToPostfix(infixExpression, postfixExpression);

    struct TreeNode* root = buildTreeFromPostfix(postfixExpression);
    int result = evaluateExpression(root);

    printf("Result: %d\n", result);

    return 0;
}
