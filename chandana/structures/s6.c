#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a stack
struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data)
{
    struct StackNode* stackNode = 
      (struct StackNode*)
      malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root)
{
    return !root;
}

void push(struct StackNode** root, int data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main()
{
    struct StackNode* root = NULL;
    char str[] = "Hello, World!";
    int length = strlen(str);

    // Push all characters of the string onto the stack
    for (int i = 0; i < length; i++) {
        push(&root, str[i]);
    }

    // Pop characters from the stack to reverse the string
    printf("Reversed string: ");
    for (int i = 0; i < length; i++) {
        printf("%c", pop(&root));
    }
    printf("\n");

    return 0;
}
