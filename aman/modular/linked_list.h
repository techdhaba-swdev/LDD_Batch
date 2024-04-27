#ifndef LINKED_LIST_H //    This is a preprocessor directive that checks if the macro LINKED_LIST_H is not defined. If it's not defined, it proceeds with the code inside the #ifndef block. This construct is used to prevent multiple inclusions of the header file, ensuring that it's included only once in a compilation unit.


#define LINKED_LIST_H//If the macro LINKED_LIST_H was not defined previously, this line defines it now. This ensures that subsequent attempts to include the header file won't enter the #ifndef block, preventing multiple inclusions.

struct Node {//This defines a structure named Node, which represents a node in the linked list. It contains two members: data, which stores the integer value of the node, and next, which is a pointer to the next node in the list.
    int data;
    struct Node *next;
};

struct Node *createNode(int data);//This line declares a function prototype for createNode, which is responsible for creating a new node with the given data value and returning a pointer to it.
struct Node *insertFront(struct Node *head, int data);//This line declares a function prototype for insertFront, which inserts a new node with the given data value at the front of the linked list. It takes the current head of the list (head) and the data value to be inserted (data) as parameters and returns a pointer to the new head of the list.
void printList(struct Node *head);//This line declares a function prototype for printList, which prints the elements of the linked list starting from the given head node. It takes the head of the list (head) as a parameter and doesn't return any value (void).
void freeList(struct Node *head);//This line declares a function prototype for freeList, which frees the memory allocated for the linked list starting from the given head node. It takes the head of the list (head) as a parameter and doesn't return any value (void).

#endif //This line closes the conditional compilation block started by #ifndef

