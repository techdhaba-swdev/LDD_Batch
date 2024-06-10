#include"insertnode.h"

struct Node* insert(struct Node* root,int data){
	if(root == NULL){
		//base case: empty tree,crete a new toor node
		return createNode(data);
	
	}
	if(data < root->data){
	       root->left = insert(root->left, data);//insert in left subtree for smaller values
	       }else if(data > root->data){
		       root->right = insert(root->right,data);//insert in right subtree for larger values
	       }else{//handle dupliacte (optional :can modify to overwrite or rejcet 
		       printf("Duplicate value:%d\n",data);
	       }
	return root;//return the (potentially modified)root node
}




