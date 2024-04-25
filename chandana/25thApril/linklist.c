#include "linklist.h"

// Create an empty linked list
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));//Allocate memeory
    list->head = NULL;//set the head of the linked list to NULL
    return list;//Return the linked list
}

// Create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));//Allocate memeory for the new node
    newNode->data = data;//assign data to the new node
    newNode->next = NULL;//set the next pointer to NULL
    return newNode;//Return the new node
}

// Add a node to the end of the list
void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);//Create a new node with the given data
    if (list->head == NULL) {//check if the list is empty
        list->head = newNode;//if the list is empty ,set the new node as the head
    } else {
        Node* current = list->head;//Start at the head of the list
        while (current->next != NULL) {//Traverse the list to find th elast node 
            current = current->next;
        }
        current->next = newNode;//Set the next pointer of the last node to the new node
    }
}

// Print the elements of the list
void printList(LinkedList* list) {
    Node* current = list->head;//Start at the head of the list
    while (current != NULL) {//Traverse the last
        printf("%d ", current->data);//Print the data of the current node
        current = current->next;//Move the next node
    }
    printf("\n");//print a new line at the end
}

// Calculate the sum of all elements in the list
int sumList(LinkedList* list) {
    int sum = 0;//Initialize to zero
    Node* current = list->head;//Start at the head of the list
    while (current != NULL) {//traverse the list
        sum += current->data;//Add the data of the current node to the sum 
        current = current->next;//Move the next node 
    }
    return sum;//Return the sum.
}
