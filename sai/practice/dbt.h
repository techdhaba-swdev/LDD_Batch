#ifndef DBT_H_
#define DBT_H_

struct Node{
	int data;
	struct Node* left;//create child left
	struct Node* right;//create child right

};

struct Node* minValue(struct Node* root);
struct Node* createNode(int data);
struct Node* insert(struct Node* root,int data);
struct  Node* search (struct Node* root,int num);
struct Node* deletenode(struct Node* root,int num);
void inorder(struct Node* root);
#endif

