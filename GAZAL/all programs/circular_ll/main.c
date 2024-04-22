#include <stdio.h>
#include "circular.c"

int main() {
    
 int size;
  printf("Enter the size of circular linked list: ");
  scanf("%d", &size);
 struct Node *head = createCircularLinkedList(size);

  int sum = sum_cll(head);

 printf("Sum of all values in  circular linked list: %d\n", sum);

   
  struct Node *current = head;
 struct Node *next;
  while (current != NULL) {
  next = current->next;
 free(current);
   current = next;
    if (current == head) {
      break;
        }
    }

    return 0;
}
