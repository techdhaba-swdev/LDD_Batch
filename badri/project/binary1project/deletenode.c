#include "node.h"
// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) { // If root is NULL                                                 
        return root; // Return root                                                    
    }
    if (data < root->data) {  // If data is less than root data                                           
        root->left = deleteNode(root->left, data);  // Recursively delete from left subtree                     
    } else if (data > root->data) {   // If data is greater than root data                                   
        root->right = deleteNode(root->right, data);  // Recursively delete from right subtree                   
    } else {    // If data matches root data                                                         
        if (root->left == NULL) {     // If left child is NULL                                   
            struct Node* temp = root->right;  // Assign right child to temporary node                           
            free(root);    // Free memory of root                                              
            return temp;     // Return right child as root                                            
        } else if (root->right == NULL) {     // If right child is NULL                           
            struct Node* temp = root->left; // Assign left child to temporary node                             
            free(root);  // Free memory of root                                                
            return temp;  // Return left child as root                                               
        }
        struct Node* temp = findMin(root->right);  // Find minimum in right subtree                      
        root->data = temp->data;  // Copy minimum value to root                                       
        root->right = deleteNode(root->right, temp->data); // Delete the minimum value node              
    }
    return root; // Return root                                                        
}
