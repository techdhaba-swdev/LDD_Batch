#include"binary_tree.h"
int main(){
	clock_t start = clock();
	double CLOCKS_PER_SEC;
	
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
	
	int totalSum = add(root);
	printf("ssum of allllllllll nodes :%d\n",totalSum);
	clock_t end = clock();
	double time_taken =((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f seconds \n",time_taken);
	return 0;
}
