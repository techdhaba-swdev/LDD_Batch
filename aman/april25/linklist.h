#ifndef LINKLIST_H // pre proccessor directive that checks macro
#define LINKLIST_H //defines the macro linklist_h and prevent it from being include multiple  time 
struct node{   // thisdefines structure called as node
	int data;  // it represents the data store in node
	struct node *next;  //represent pointer to next node in link list
};

void printList(); //declaring a function and it will print elements  of the link list.
void insertAtBegin(int data); //declaring a function insertatbegin, it will insert new node with given data at begin of list
void insertAtEnd(int data);  // declaring a function insertatend, it will insert new node with given data at end of list
void freeList(); //declaring a function to free memory allocated for the linked list
#endif // this line end of this compilation block
