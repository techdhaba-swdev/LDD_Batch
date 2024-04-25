#ifndef MYSTRUCT_H
#define MYSTRUCT_H

struct Node {                 //define the structure for singly linked list with name Node
			      //int data is member of structure represent data stored in data is integer type
    int data;             
    struct Node* next;        //second memeber in structure is struct Node* next  this is the pointer to another struct Node
};

struct Node* createNode(int value);
void insertAtStart(struct Node** head, int value);
void displayList(struct Node* head);
void deleteList(struct Node** head);
void print_message(const char *message);

#endif 

/*Header Guard: The #ifndef and #define directives with MYSTRUCT_H
 create a header guard to prevent multiple inclusions of the same header file, ensuring code is compiled only once.*/

