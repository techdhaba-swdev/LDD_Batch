#include <stdio.h>
#include "double.c"

int main() {
struct Node *head = createNode(1);
  struct Node *second = createNode(2);
 struct Node *third = createNode(3);
 struct Node *fourth = createNode(4);
  struct Node *fifth = createNode(5);

 head->next = second;
 second->prev = head;
    second->next = third;
   third->prev = second;
  third->next = fourth;
   fourth->prev = third;
  fourth->next = fifth;
    fifth->prev = fourth;
  int sum = sumDoubly(head);

 printf("Sum of all values in the doubly: %d\n", sum);
    return 0;
}
