#include"stack.h"
bool stack_is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}
