#ifndef BSTOPT_H
#define BSTOPT_H

struct Node {
	char data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(char data);
struct Node* Inorder(struct Node* root);
#endif
