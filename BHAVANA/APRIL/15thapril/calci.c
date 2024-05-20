#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;


Node* createStack() {
  Node* head = NULL;
  return head;
}

void push(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}


int pop(Node** head) {
  if (*head == NULL) {
    return -1;
  }
  int data = (*head)->data;
  Node* temp = *head;
  *head = (*head)->next;
  free(temp);
  return data;
}


int isEmpty(Node* head) {
  return head == NULL;
}


int evaluate(Node* head) {
  int result = 0;
  while (!isEmpty(head)) {
    int operand2 = pop(&head);
    int operator = pop(&head);
    int operand1 = pop(&head);

    switch (operator) {
      case '+':
        result = operand1 + operand2;
        break;
      case '-':
        result = operand1 - operand2;
        break;
      case '*':
        result = operand1 * operand2;
        break;
      case '/':
        result = operand1 / operand2;
        break;
    }
  }
  return result;
}


int main() {
  
  Node* stack = createStack();

  
  push(&stack, 20);
  push(&stack, '-');
  push(&stack, 5);
  push(&stack, '*');
  push(&stack, 2);

  
  int result = evaluate(stack);

 
  printf("Result: %d\n", result);

  return 0;
}
