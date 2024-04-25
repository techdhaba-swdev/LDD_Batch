#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void stack_init(Stack *s) ;
void stack_push(Stack *s, int data);
int stack_pop(Stack *s);
bool stack_is_empty(Stack *s);
bool stack_is_full(Stack *s);

