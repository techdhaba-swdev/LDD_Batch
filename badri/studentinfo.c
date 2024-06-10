#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student record
typedef struct Student {
    int id;
    char name[100];
} Student;

// Define the node structure for the binary search tree (BST)
typedef struct BSTNode {
    Student data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Define the node structure for the linked list
typedef struct ListNode {
    Student data;
    struct ListNode* next;
} ListNode;

// Function to create a new BST node
BSTNode* createBSTNode(Student data) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to add a student to the BST
BSTNode* addStudent(BSTNode* root, Student data) {
    if (root == NULL) {
        return createBSTNode(data);
    }
    if (data.id < root->data.id) {
        root->left = addStudent(root->left, data);
    } else if (data.id > root->data.id) {
        root->right = addStudent(root->right, data);
    } else {
        printf("Student with ID %d already exists.\n", data.id);
    }
    return root;
}

// Function to search for a student by ID in the BST
BSTNode* searchStudent(BSTNode* root, int id) {
    if (root == NULL || root->data.id == id) {
        return root;
    }
    if (id < root->data.id) {
        return searchStudent(root->left, id);
    }
    return searchStudent(root->right, id);
}

// Function to find the minimum node in the BST
BSTNode* findMin(BSTNode* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Function to delete a student by ID from the BST
BSTNode* deleteStudent(BSTNode* root, int id) {
    if (root == NULL) {
        return root;
    }
    if (id < root->data.id) {
        root->left = deleteStudent(root->left, id);
    } else if (id > root->data.id) {
        root->right = deleteStudent(root->right, id);
    } else {
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        BSTNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteStudent(root->right, temp->data.id);
    }
    return root;
}

// Function to convert the BST to a linked list
void bstToList(BSTNode* root, ListNode** head) {
    if (root == NULL) return;
    bstToList(root->right, head);
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = root->data;
    newNode->next = *head;
    *head = newNode;
    bstToList(root->left, head);
}

// Function to merge two sorted linked lists
ListNode* sortedMerge(ListNode* a, ListNode* b) {
    ListNode* result = NULL;
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (strcmp(a->data.name, b->data.name) <= 0) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

// Function to split a linked list into two halves
void splitList(ListNode* source, ListNode** front, ListNode** back) {
    ListNode* fast;
    ListNode* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

// Function to sort the linked list using merge sort
void mergeSort(ListNode** headRef) {
    ListNode* head = *headRef;
    ListNode* a;
    ListNode* b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        printf("ID: %d, Name: %s\n", head->data.id, head->data.name);
        head = head->next;
    }
}

// Main function to test the implementation
int main() {
    BSTNode* root = NULL;

    Student s1 = {1, "Amit"};
    Student s2 = {2, "Badri"};
    Student s3 = {3, "Charan"};
    Student s4 = {4, "Dinesh"};
    
    root = addStudent(root, s1);
    root = addStudent(root, s2);
    root = addStudent(root, s3);
    root = addStudent(root, s4);

    printf("Search for student with ID 2:\n");
    BSTNode* found = searchStudent(root, 2);
    if (found != NULL) {
        printf("Found student: ID: %d, Name: %s\n", found->data.id, found->data.name);
    } else {
        printf("Student not found.\n");
    }

    printf("\nDeleting student with ID 3:\n");
    root = deleteStudent(root, 3);

    printf("\nAll students sorted by name:\n");
    ListNode* head = NULL;
    bstToList(root, &head);
    mergeSort(&head);
    printList(head);

    return 0;
}
