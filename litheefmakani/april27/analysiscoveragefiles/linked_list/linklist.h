// linklist.h
struct node;  // forward the declaration of struct node from linklist.c without exposing code this file linklist.h
struct node *createLinkedlist(); // create linkedlist returning pointer head node 
void show(struct node *head);  // it prints values of linkedlist
void freelinkedlist(struct node *head);// it will deallocate the memory with preventing from memory leaks
