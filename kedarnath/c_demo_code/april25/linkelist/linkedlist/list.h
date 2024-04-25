
#ifndef LIST_H // This checks if the macro LIST_H is not defined. If it's not defined, it means that this is the first time this header file is being included in the current translation unit

#define LIST_H // If LIST_H is not defined, this line defines it. This effectively prevents the code within the #ifndef and #endif block from being included again if this header file is included in subsequent files.

#include <stdio.h> // it includes standrd input/ouput function present inside stdio.h files
#include <stdlib.h> // it inclued the standard library function present inside the stdlib.h files



// Function prototypes
void printList(); // declairing the function printlist tom print value present inside the linked list

void insertAtBegin(int data); // this function insert the node at the begining of the list

void insertAtEnd(int data); // this function insert the node at the end of the list

//void insertAfterNode(struct node *list, int data);

void deleteAtBegin(); // this function delete the node at the begining of the list

void deleteAtEnd(); // this function delete the node at the end of the list

void deleteNode(int key); // this function delete the node the list by its value
 
int searchList(int key); // this function search the node the list by its value

#endif /* LIST_H */ // This marks the end of the conditional compilation block.

