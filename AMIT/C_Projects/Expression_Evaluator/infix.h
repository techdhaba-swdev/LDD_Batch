#ifndef INFIX
#define INFIX

// Stack implementation for operands
struct StackNode {
    double value;
    struct StackNode* next;
};

struct StackNode* createStackNode(double value);
void push(struct StackNode** stack, double value);
double pop(struct StackNode** stack);
int precedence(char op) ;
void infixToPostfix(const char* infix, char* postfix) ;
double evaluatePostfix(const char* postfix);

#endif 
