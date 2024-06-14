#include"search.h"
int search(struct node* root, int data){
	if(root==NULL){
		return 0;
	}
	if(root->data==data){
		return 1;
	}else if(data<root->data){
		return search(root->left,data);
	}else{
		return search(root->right,data);
	}
}
