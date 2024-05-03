#include "node.h"
// Function to find the maximum value in the BST
struct Node* findMax(struct Node* root) {
    if (root == NULL) {// If root is NULL
        return NULL;  // Return NULL                                                   
    }
    if (root->right == NULL) {  // If right child is NULL                                         
        return root; // Return the root                                                    
    }
    return findMax(root->right); // Recursively find maximum in the right subtree                                        
}
