#include"tree.h"
int main() {
 	struct Node* root = NULL;
 	root = insert(root, 50);
 	insert(root, 30);
 	insert(root, 20);
 	insert(root, 40);
 	insert(root, 70);
 	insert(root, 60);
 	insert(root, 80);
 
	printf("In-order traversal: ");
 	inOrder(root);
 	printf("\n");
	printf("sum is %d\n",sumOfNodes(root));
 
	return 0;
 }

