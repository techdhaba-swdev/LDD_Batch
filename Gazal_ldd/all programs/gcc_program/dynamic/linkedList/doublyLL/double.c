#include "doubly_ll.h"
#include <stdio.h>
#include <stdlib.h>

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
 if (newNode == NULL) {
   printf("Memory allocation failed.\n");
        exit(1);
    }
  newNode->data = data;
 newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

int sumDoubly(struct Node *head) {
    int sum = 0;
    struct Node *current = head;
    while (current != NULL) {
 sum += current->data;
        current = current->next;
    }
    return sum;
}
