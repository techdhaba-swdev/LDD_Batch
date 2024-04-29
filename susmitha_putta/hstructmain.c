#include <stdio.h>
#include <stdlib.h>
int main() {
    struct node*root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 8);

    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    int searchData = 8;
    if (search(root, searchData)) {
        printf("%d found in the BST.\n", searchData);
    } else {
        printf("%d not found in the BST.\n", searchData);
    }

    searchData = 12;
    if (search(root, searchData)) {
        printf("%d found in the BST.\n", searchData);
    } else {
        printf("%d not found in the BST.\n", searchData);
    }

    return 0;
}
