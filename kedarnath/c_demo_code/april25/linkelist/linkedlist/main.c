#include "list.h" // including the list.h header file

int main() {
    int k = 0; // declaring and initializing k value 

    // Example usage
    insertAtBegin(12); // inserting node at begining with value of 12
    insertAtBegin(22); // inserting node at begining with value of 22
    insertAtEnd(30); // inserting node at end with value of 30
    insertAtEnd(44); // inserting node at end with value of 44
    insertAtBegin(50); // inserting node at begining with value of 50
    //insertAfterNode(head->next->next, 33);

    printf("Linked List: ");
    printList(); // print the value present inside the list

    deleteAtBegin(); // deleting first element in the list
    deleteAtEnd(); // deleting last element in the list
    deleteNode(12); // deleting element in the listbased on its value

    printf("\nLinked List after deletion: ");
    printList();

    insertAtBegin(4); // inserting node at begining with value of 4
    insertAtBegin(16); // inserting node at begining with value of 16

    printf("\nUpdated Linked List: ");
    printList(); // print the value present inside the list

    int data;
    printf("\nEnter value to find: ");
    scanf("%d", &data); // taking user input to find the element present inside the list

    k = searchList(data); // if value of k is 1 then element is present inside list otherwise not present inside the list
    if (k == 1)
        printf("Element is found\n");
    else
        printf("Element is not present in the list\n");

    return 0;
}

