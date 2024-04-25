#include<stdio.h>
#include<stdlib.h>
#include"mystruct.h"

// Function to free memory and delete the entire list
void deleteList(struct Node** head) {                   //deleteList is function with parameter struct Node** head ,is a pointer to the 
							//pointer to head 
    struct Node* current = *head;                //local ponter current is initialize with a value of head ponter
    while (current != NULL) {                    //while loop is to travers linked list , loop cont. untill current become zero
        struct Node* temp = current;         //temp ponter assign value of current
        current = current->next;       //current pointer is updated to point next node
        free(temp);                    //memory occupied by temp is free using free()
    }
    *head = NULL;                   //head pointer set to NULL to indicate list is now empty
}

