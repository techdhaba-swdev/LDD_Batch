#include<stdio.h>
#include<stdlib.h>
#include"mystruct.h"

int main() {
    struct Node* head = NULL;        //decleared ponter variable name head initially set to NULL indicate list is empty

    // Insert nodes at the beginning
    insertAtStart(&head, 10);              //caling fn insertAtStart to insert nodes and head pointer is updated to point to 
					   //new inserted node.   
    insertAtStart(&head, 20);
    insertAtStart(&head, 30);

    // Display the linked list
    print_message("Linked List: ");
    displayList(head);                         //displayList is called to display data of the list

    // Clean up and free memory  
    deleteList(&head);                    //deleteList is called to free memory occupied by all node in the list 
					  //head set to NULL indicate list is empty now

    return 0;
}
