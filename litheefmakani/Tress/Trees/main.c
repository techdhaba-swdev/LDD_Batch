#include"node.c"
#include"insert.c"
#include"search.c"
#include"inordertraversal.c"
int main(){
	struct node* root = NULL;

	//inserting nodes into the BST
	root = insert(root,50);
	root = insert(root,30);
	root = insert(root,70);
	root = insert(root,20);
	root = insert(root,40);
	root = insert(root,60);
	root = insert(root,80);

	//performing inordertraversal to verify bst structure
	printf("In order traversal:");
	inordertraversal(root);
	printf("\n");

	//searchng for nodes in the BST
	int key=40;
	if(search(root,key)){
			printf("%d is found in the BST \n",key);
	}else{
		printf("%d is not found in the BST\n",key);
	}
	return 0;
}
			
