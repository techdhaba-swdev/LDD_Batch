typedef struct {
        int *data;
        int top;
        int capacity;
}Stack;
int stack_push(Stack *stack,int data);
