#include <stdio.h>//This line includes the standard input-output library, which provides functions like printf() and scanf() for input and output operations.
#include "linked_list.h"// This line includes the header file linked_list.h, which contains the structure definition and function prototypes related to the linked list.

int main() {//This line defines the main function, which serves as the entry point of the program. It returns an integer value to the operating system upon completion.
    struct Node *head = NULL;//This line declares a pointer variable head of type struct Node* and initializes it to NULL. This pointer will serve as the head of the linked list.

    
    head = insertFront(head, 3);//These lines demonstrate the insertion of elements at the front of the linked list. Each call to insertFront inserts a new node with the specified data value (3, 5, 7) at the front of the list. The updated head pointer is assigned back to head after each insertion.
    head = insertFront(head, 5);
    head = insertFront(head, 7);

    
    printf("Linked list: ");//These lines print the elements of the linked list to the console. First, a message "Linked list: " is printed, indicating the start of the list. Then, the printList function is called with the head pointer as an argument to print the elements of the linked list.
    printList(head);

    
    freeList(head);//This line calls the freeList function with the head pointer as an argument to free the memory allocated for the linked list. This ensures that memory allocated for each node in the list is properly deallocated.

    return 0;//This line indicates successful termination of the program by returning 0 to the operating system. This value is conventionally used to indicate successful execution of the program.
}

