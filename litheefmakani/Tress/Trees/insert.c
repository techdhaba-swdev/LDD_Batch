#include"insert.h"
#include<stdio.h>
struct node* insert(struct node* root,int data){
	if(root == NULL){
		return createNode(data);
	}
	if(data< root->data){
		root->left = insert(root->left,data);
	}else if(data > root->data){
		root->right = insert(root->right,data);
	}
	return root;
}
