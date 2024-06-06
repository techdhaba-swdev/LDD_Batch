#ifndef BST_H
#define BST_H



//struct definition for a node
struct Node {
	int data; //data stored in node
	
	struct Node* left; //Pointer to the left node
	struct Node* right; //Pointer to the right node
};

struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
struct Node* deletion(struct Node* root, int data);
struct Node* Minimum(struct Node* node);
void preorder(struct Node* root);
void postorder(struct Node* root);


void MinMax(struct Node* node, int *min, int *max);
void inOrderTraversal(struct Node* root);
int height(struct Node* node);

#endif
