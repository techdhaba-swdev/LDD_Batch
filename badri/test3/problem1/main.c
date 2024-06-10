#include "header.h"

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

