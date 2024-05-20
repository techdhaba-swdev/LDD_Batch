#include <stdio.h>
#define MAX_SIZE 100 
typedef struct {
        int items[MAX_SIZE];
        int top;
}stack;
void initialize(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
