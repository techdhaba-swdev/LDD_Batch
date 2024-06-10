#include "header.h"
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

