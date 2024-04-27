#include "linked_list.h" // we are including the linked_list.h file 
#include <stdio.h>       // including the strandred input/output functions
#include<stdlib.h>       // including the strandard library functions

int main() {
	struct node *head = NULL;  // declaring the head pointer with NULL
    int k = 0;                     // inistalizing the k to 0
    insertatbegin(12);             // calling the insertatbegin function
    insertatbegin(22);             
    insertatend(30);               // calling the insertatend function
    insertatend(44);
    insertatbegin(50);          
    printf("Linked List: ");
    printList();                   // calling the function to print values
    deleteatbegin();               // caling the deleteatbegin function
    deleteatend();                 // calling the deleteatend funtion 
    deletenode(12);                // calling the deletenode function
    printf("\nLinked List after deletion: ");
    printList();
    insertatbegin(4);
    insertatbegin(16);
    printf("\nUpdated Linked List: ");
    printList();
    k = searchlist(16);            // calling the function search list with value
    if (k == 1)
        printf("\nElement is found");
    else
        printf("\nElement is not present in the list");

    // Free memory for all dynamically allocated nodes before exiting 
    // AND this is called secure coding
    struct node *current = head;
    struct node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    return 0;                    // this ensures that main function is execute 
}
