#include "node.h"

// Define the structure of the linked list
typedef struct List {
    Node *head;  // Pointer to the head of the list
} List;
Node *createNode(int data);
// Function prototypes for list operations
List *createList();
void insertAtEnd(List *list, int data);
void displayList(List *list);
void deleteList(List *list);
