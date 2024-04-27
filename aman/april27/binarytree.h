#ifndef BINARYTREE_H //this line start preprocessor directive which checks if the macro binarytree.h has not define before
#define BINARYTREE_H// this line defines macro binarytree.h and check that the content of header fileare included once in compilation process also  it prevents multiple  definition.
struct TreeNode{//this line defines  a structure named TreeNode which represet node in binary tree
	int data;//this line declares an integer variablr data inside the treenode structurewhich will stores  value of node
	struct TreeNode* left;//this line declares a pointer left inside treenode which points to  left chlid node  of current node
	struct TreeNode* right;// this line declares a pointer right inside treenode which points right chlid node of current node
};
struct TreeNode* createTreeNode(int data);//this line declare function prototypes for creating a new tree node.
struct TreeNode* insert(struct TreeNode* root, int data);//this line declares function insert to a node into binarysearchtree
int search(struct TreeNode* root, int data);//this line declares function searchto search for a node into binary s.tree
struct TreeNode* deleteNode(struct TreeNode* root, int data);//this line declare function deletenode to delete a node from tree
void inOrderTraversal(struct TreeNode* root);//this line declare function to perform inorder traversal
void preOrderTraversal(struct TreeNode* root);//this line declares function to perform pree ordertraversal
void postOrderTraversal(struct TreeNode* root);//this line declares function to perfom post order traversal
#endif//this line ends the conditional compilation started by ifndef
