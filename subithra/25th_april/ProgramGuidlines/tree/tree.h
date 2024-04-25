//This line starts an include guard. It ensures that the content of the header file is only included once in a translation unit.
//TREE_H is a macro name, chosen to be unique to this header file.
#ifndef TREE_H
#define TREE_H //this line defines the macro TREE_H, indicating that the header file has been included in a translation unit.

#include <stdbool.h>//This line includes the standard C header file stdbool.h, which defines the boolean data type and its values true and false.

// Define the structure for a tree node
struct TreeNode;

// Function prototypes
struct TreeNode* createNode(int data); // Create a new tree node
struct TreeNode* insertNode(struct TreeNode* root, int data);//This line declares a function prototype for insertNode. It inserts a node with the given data into the binary tree with the specified root node and returns the root of the modified tree.
void inorderTraversal(struct TreeNode* root); //This line declares a function prototype for inorderTraversal. It performs an inorder traversal of the binary tree rooted at root, printing the data of each node in ascending order.

#endif//This line ends the include guard and the header file's content. It ensures that the content of the header file is included only once per translation unit.
