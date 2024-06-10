#include"inorder.h"

void inorder(struct Node* root){//defining function defininge
	if(root != NULL){
		inorder(root->left);//visit left subtree
		printf("%d",root->data);//visit current node
		inorder(root->right);//visit right subtree
	}
}
