#include <stdio.h>
#include"my_libraries.c"
int main() {
 
struct Node *head = createNode(1);
 head->next = createNode(2);
head->next->next = createNode(3);
 head->next->next->next = createNode(4);
head->next->next->next->next = createNode(5);
    
    int sum = sumLinkedList(head);
 printf("Sum of all values in the linked list: %d\n", sum);

    return 0;
    }
