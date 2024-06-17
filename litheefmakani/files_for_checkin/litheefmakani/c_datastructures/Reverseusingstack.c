#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack {
    int top;
    char items[MAX_SIZE];
};
void initializeStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char c) {
    s->items[++(s->top)] = c;
}

char pop(struct Stack *s) {
    return s->items[(s->top)--];
}

void reverseString(char *str) {
    struct Stack s;
    initializeStack(&s);
    for (int i = 0; i < strlen(str); i++) {
        push(&s, str[i]);
    }
    
    int i = 0;
    while (!isEmpty(&s)) {
        str[i++] = pop(&s);
    }
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';
    reverseString(str);
    
    printf("Reversed string: %s\n", str);
    
    return 0;
}