#include"main.h"
int main(){
	struct Node* root = NULL;
	root = insert(root,50);
	insert(struct Node* root,30);
	insert(struct Node* root,20);
	insert(struct Node* root,40);
	insert(struct Node* root,70);
	insert(struct Node* root,60);
	insert(struct Node* root,80);
	printf("In-order traversal : ");
	inorder(struct Node* root);
	printf("\n");
	return 0;
}
