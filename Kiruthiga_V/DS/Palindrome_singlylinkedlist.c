#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to reverse a singly linked list
void reverseList(Node** head_ref) {
    Node *prev = NULL, *current = *head_ref, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Function to check if a linked list is a palindrome
int isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return 1; // Empty list or single element list is palindrome
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev_slow = NULL;
    Node* mid = NULL;
    int result = 1;

    // Use fast and slow pointers to find the middle of the list
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    // If the length of the list is odd, move slow one step further
    if (fast != NULL) {
        mid = slow;
        slow = slow->next;
    }

    // Reverse the second half of the list
    reverseList(&slow);

    // Compare the first half with the reversed second half
    Node* current1 = head;
    Node* current2 = slow;
    while (current2 != NULL) {
        if (current1->data != current2->data) {
            result = 0;
            break;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    // Restore the original list by reversing the second half back
    reverseList(&slow);

    // If the length of the list is odd, reposition mid to its original position
    if (mid != NULL) {
        prev_slow->next = mid;
        mid->next = slow;
    } else {
        prev_slow->next = slow;
    }

    return result;
}

// Function to display the linked list
void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free memory allocated for the linked list
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Main function to test the linked list operations
int main() {
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);

    printf("Linked list:\n");
    display(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    freeList(head); // Free memory allocated for the linked list
    return 0;
}



