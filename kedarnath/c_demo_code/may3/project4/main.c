#include"binarytree.h"

int main() {

    clock_t start=clock();
    Node* root = NULL;

    // Insert some nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print in-order traversal (should be sorted)
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Print pre-order traversal
    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    // Print post-order traversal
    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    // Check if BST
    printf("Is BST? %s\n", isBST(root) ? "Yes" : "No");

    // Find height of BST
    printf("Height of BST: %d\n", height(root));

    // Find minimum and maximum values
    int min, max;
    findMinMax(root, &min, &max);
    printf("Minimum value in BST: %d\n", min);
    printf("Maximum value in BST: %d\n", max);

    // Search for a value
    int searchValue = 30;
    Node* searchResult = search(root, searchValue);
    printf("Search for value %d: %s\n", searchValue, searchResult ? "Found" : "Not found");

    // Delete a node
    int deleteValue = 20;
    root = delete(root, deleteValue);
    printf("In-order traversal after deleting %d: ", deleteValue);
    inOrderTraversal(root);
    printf("\n");

    clock_t end=clock();
    double time_taken=((double)(end-start));
    printf("time taken is %f\n",time_taken);
    

    return 0;
}

