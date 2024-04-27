#include "linked_list.h"//This line includes the header file linked_list.h, which contains the structure definition and function prototypes related to the linked list.
#include <stdlib.h>//this line is standard library for which provide functions like malloc() for memory allocation 
#include <stdio.h>//this line is standard input output library required for printf,scaf

struct Node *createNode(int data) {//This line defines the createNode function. It takes an integer data as a parameter and returns a pointer to a new node (struct Node *). This function is responsible for dynamically allocating memory for a new node, initializing its data field with the given value, and setting its next pointer to NULL.
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));// This line dynamically allocates memory for a new node using malloc(). It allocates memory equivalent to the size of the Node structure and assigns the pointer to the allocated memory to the newNode variable.
    if (newNode != NULL) {//This line checks if the memory allocation was successful by verifying if newNode is not NULL. If memory allocation fails, malloc() returns NULL
        newNode->data = data;//This line assigns the value of data to the data field of the newly created node.
        newNode->next = NULL;//This line sets the next pointer of the newly created node to NULL, as it is the last node in the list initially.
    }
    return newNode;//These lines close the if block and the createNode function definition, respectively. If memory allocation was successful, the function returns a pointer to the newly created node. If memory allocation failed, it returns NULL.
}

struct Node *insertFront(struct Node *head, int data) {//This line defines the insertFront function. It takes a pointer to the head of the linked list (head) and an integer data as parameters and returns a pointer to the new head of the list (struct Node *). This function inserts a new node with the given data value at the front of the linked list.
    struct Node *newNode = createNode(data);// This line creates a new node with the given data value using the createNode function.
    if (newNode != NULL) {// This line checks if the new node was successfully created.
        newNode->next = head;//This line sets the next pointer of the new node to the current head of the list, effectively making the new node the new head.
        head = newNode;//This line updates the head pointer to point to the newly inserted node, making it the new head of the list.
    }
    return head;//These lines close the if block and the insertFront function definition, respectively. If the new node was successfully created, the function returns a pointer to the new head of the list. If the new node creation failed, it returns the original head of the list.
}

void printList(struct Node *head) {//This line defines the printList function. It takes a pointer to the head of the linked list (head) as a parameter and doesn't return any value (void). This function prints the elements of the linked list to the console.
    struct Node *current = head;//This line declares a pointer variable current and initializes it with the head pointer. This pointer will be used to traverse the list.
    while (current != NULL) {//This line starts a while loop that iterates until the current pointer reaches the end of the list (i.e., until it becomes NULL).
        printf("%d ", current->data);//This line prints the value of the data field of the current node to the console.
        current = current->next;//This line moves the current pointer to the next node in the list by following the next pointer.
    }
    printf("\n");//     These lines close the while loop and the printList function definition, respectively. After printing all the elements of the list, a newline character is printed to move the cursor to the next line.


}

void freeList(struct Node *head) {//This line defines the freeList function. It takes a pointer to the head of the linked list (head) as a parameter and doesn't return any value (void). This function frees the memory allocated for the linked list.
    struct Node *temp;//This line declares a pointer variable temp, which will be used to temporarily store the address of nodes to be deleted.
    while (head != NULL) {//This line starts a while loop that iterates until the head pointer reaches the end of the list (i.e., until it becomes NULL).
        temp = head;// This line assigns the value of the head pointer to the temp pointer, preserving the address of the current node to be deleted.
        head = head->next;//This line moves the head pointer to the next node in the list, preparing for the deletion of the current node.
        free(temp);//This line frees the memory allocated for the current node by using the free() function.
    }
}
//secure code It also ensures secure programming practices by handling memory allocation and freeing allocated memory properly.
