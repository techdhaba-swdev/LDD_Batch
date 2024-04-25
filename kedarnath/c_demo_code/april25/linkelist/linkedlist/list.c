#include "list.h" // including list.h header file


struct node {
    int data;
    struct node *next;
};

// Define global variables
struct node *head = NULL;
struct node *current = NULL;

// Function definitions
void printList() {
    struct node *p = head;
    printf("\n[");

    //start from the beginning
    while (p != NULL) {
        printf(" %d ", p->data);
        p = p->next;
    }
    printf("]");
}

void insertAtBegin(int data) {
    //create a link
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    // point it to old first node
    newNode->next = head;

    //point first to new first node
    head = newNode;
}

void insertAtEnd(int data) {
    //create a link
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    struct node *linkedlist = head;

    // point it to old first node
    while (linkedlist->next != NULL)
        linkedlist = linkedlist->next;

    //point first to new first node
    linkedlist->next = newNode;
}

/*void insertAfterNode(struct node *list, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = list->next;
    list->next = newNode;
}*/

void deleteAtBegin() {
    head = head->next;
}

void deleteAtEnd() {
    struct node *linkedlist = head;
    while (linkedlist->next->next != NULL)
        linkedlist = linkedlist->next;
    linkedlist->next = NULL;
}

void deleteNode(int key) {
    struct node *temp = head, *prev;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        return;
    }

    // Find the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL) return;

    // Remove the node
    prev->next = temp->next;
}

int searchList(int key) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

