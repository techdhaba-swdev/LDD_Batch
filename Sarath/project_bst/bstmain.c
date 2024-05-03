//INCLUDING HEADER FILES

#include<stdio.h>
#include<time.h>
#include"bst.h"

//CREATED A STRUCTURE TO STORE DATA AND LEFT,RIGHT POINTERS FOR CONNECTION BETWEEN NODES
struct node 
{
	int data;
	struct node *left;
	struct node *right;
};
int main()
{
	int ele;
	clock_t start=clock(); //CALCULATING START TIME USING CLOCK() 
	struct node *root=NULL; //INITIALIZING ROOT NODE WITH NULL
	//INSERTING NODES TO BINARYSEARCH TREE USING INSERT API
	root=insert(root,50); 
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	printf("BINARY TREE USING INORDER TRAVERSING :"); //PRINTING BINARYSEARCH TREE 
	inordertraversal(root); //USING INORDERTRAVERSAL API TRAVERSING THROUGH THE TREE AND PRINTING EACH ELEMENT
	printf("\n");
	printf("BINARY TREE USING PRE :"); //PRINTING BINARYSEARCH TREE 
        preorder(root); //USING PREORDER API TRAVERSING THROUGH THE TREE AND PRINTING EACH ELEMENT
        printf("\n");
	printf("BINARY TREE USING POSTORDER :"); //PRINTING BINARYSEARCH TREE 
        postorder(root); //USING POSTORDER API TRAVERSING THROUGH THE TREE AND PRINTING EACH ELEMENT
        printf("\n");
	int h=height(root);
	printf("Height of tree is : %d",h);
	printf("\n");
	int c=count(root);
	printf("NUMBER OF NODES : %d",c);
	printf("\n");
	printf("Enter element to find:");
	scanf("%d",&ele); //TAKING FROM USER WHICH ELEMENT TO FIND
	if (search(root, ele) != NULL) //PERFORMED SEARCH OPERATION TO FIND REQUIRED ELEMENT FROM USER
        {
                printf("Yes,%d is found\n",ele);
        }
        else
        {
                printf("OOPS!! %d not found\n",ele);
        }
        struct node* temp = delete (root, 70); //PERFORMED DELETE OPERATION TO DELETE REQUIRED ELEMENT FROM TREE
        
	printf("After Deleting Required Node : ");
        inordertraversal(root); //CALLING INORDERTRAVERSAL AFTER DELETING NODE AND PRINTINF THE TREE AGAIN
        printf("\n");
        
	int min=*(int *)find_min(root); //TYPECASTED THE fin_min API AS IT IS OF STRUCT TYPE
        printf("Minimum element in Tree : %d\n",min);
        
	int max=*(int *)find_max(root); //TYPECASTED THE fin_max API AS IT IS OF STRUCT TYPE
        printf("Maximum element in Tree: %d\n",max);
        
	int sum=calculatesum(root); //CALCULATING THE SUM OF ALL NODES USING CALCULATESUM API
        printf("Sum of elements is %d\n",sum);
        free(root); //FREEING THE ROOT AT THE END
        
	clock_t end=clock(); //ENDING THE CLOCK TIME
        double time_taken=((double)(end-start)); //CALCULATING THE TOTAL TIMETAKEN BY MACHINE
        printf("Time taken is %f\n",time_taken); //PRINTIGN THE TIME TAKEN BY MACHINE
    	return 0;
}
