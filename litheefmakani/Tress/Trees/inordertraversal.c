#include"inordertraversal.h"
void inordertraversal(struct node* root){
	if(root !=NULL){
		inordertraversal(root->left);
		printf("%d",root->data);
		inordertraversal(root->right);
	}
}
