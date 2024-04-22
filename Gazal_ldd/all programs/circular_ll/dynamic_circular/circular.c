#include "circular.h"
#include <stdio.h>
#include <stdlib.h>

struct Node *createCircularLinkedList(int size) {
 struct Node *head = NULL;
 struct Node *prev = NULL;
printf("Enter the values for the circular linked list:\n");
 for (int i = 0; i < size; i++) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   if (newNode == NULL) {
   printf("Memory allocation failed.\n");
       exit(1);
        }

   printf("Enter value for node %d: ", i + 1);
  scanf("%d", &newNode->data);

   if (head == NULL) {
            head = newNode;
    } else {
            prev->next = newNode;
     }

   prev = newNode;
    }

  if (head != NULL) {
     prev->next = head;
    }

 return head;
}

int sum_cll(struct Node *head) {
if (head == NULL) {
        return 0;
    }

 struct Node *current = head;
 int sum_cll = 0;
    do {
        sum_cll += current->data;
        current = current->next;
    } while (current != head);

    return sum_cll;
}
