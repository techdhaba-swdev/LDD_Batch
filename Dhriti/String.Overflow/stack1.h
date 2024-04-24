#define MAX_SIZE 50
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void init(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);


