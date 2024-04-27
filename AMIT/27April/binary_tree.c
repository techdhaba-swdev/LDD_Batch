#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

int main()
{
	struct node* root =NULL;
	root = insert(root,69);
	insert(root,35);                   //inserting nodes by insert function
	insert(root,21);                  
	insert(root,45);
	insert(root,77);
	insert(root,66);
	insert(root,88);

    printf("In-order traversal: ");
    inorderTraversal(root);                          
    printf("\n");
    printf("Minimum value in the BST: %d\n", minValueNode(root)->data);
    printf("Maximum value in the BST: %d\n", maxValueNode(root)->data);
    printf("Height of the BST: %d\n", treeHeight(root));

    int searchValue = 45;
    if (search(root, searchValue))
        printf("%d found in the BST.\n", searchValue);
    else
        printf("%d not found in the BST.\n", searchValue);

    return 0;
}
