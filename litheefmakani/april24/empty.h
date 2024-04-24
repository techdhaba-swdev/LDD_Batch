#include<stdbool.h>
typedef struct {
        int *data;
        int top;
        int capacity;
}Stack;
bool stack_is_empty(Stack *stack);
