#include<stdio.h>
#include"linkedlist.h"
int main()
{
struct Node* head =NULL; // insert nodes into the linked list
insertAtBeginning(&head, 12);
insertAtBeginning(&head, 24);
insertAtBeginning(&head, 36);
printf("link list elements:\n"); 
printList(head);//print the linked list
freeList(head); // free memory allocated for the linked list
return 0;
}
