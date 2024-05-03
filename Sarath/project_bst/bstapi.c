#include<stdio.h>
#include"bst.h"
#include<math.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

//CREATE NODE API TO CREATENODE BY TAKING NODE DATA
struct node* createnode(int data) 
{
    struct node* temp = (struct node*)malloc(sizeof(struct node)); //creating space everytime to store
    temp->data = data; //storing data into temp
    temp->left = NULL; //Initializing left child of parent node to NULL
    temp->right = NULL; //Initializing right child of parent node to NULL
    return temp;
}

//INSERT API FOR INSERTING DATA TO BINARY TREE
struct node* insert(struct node* node, int data) 
{
    if (node == NULL) 
    {
        return createnode(data); //If the tree is NULL then we are creating the node using creaatenode API(Used for 1st insertion)
    }

    // Recursively inserting nodes to tree based on data value
    if (data < node->data) 
    {
        node->left = insert(node->left, data); //Checking if data is lessthan node data then inserting the data to left of node
    } else if (data > node->data) {
        node->right = insert(node->right, data); //Checking if data is greaterthan node data then inserting the data to right of node
    }
    return node;
}
// Search API FOR SEARCHING REQUIRED NODE IN BINARY TREE
struct node* search(struct node* node, int data) 
{
    if (node == NULL || node->data == data) 
    {
        return node;
    }

    // Recursively search based on data value
    if (data < node->data) 
    {
        return search(node->left, data); //Checks if given node is less than the node then search from nodeleft
    } else {
        return search(node->right, data); //else case of if written above
    }
}
int count(struct node *root) //CALCULATING NO. OF NODES IN THE TREE
{
	if(root==NULL) return 0;
	int left_count=count(root->left);
	int right_count=count(root->right);
	return left_count+right_count+1;
}
//fin_min API TO FIND MINIMUM NODE IN THE BINARY TREE
struct node* find_min(struct node* node) 
{
    if (node == NULL) //For better practice checking if the node is NULL then return node
    {
        return node;
    }
    else if (node->left != NULL) 
    { //recursively checking for the required node in left sub tree
        return find_min(node->left);
    }
    return node; // Traverse left subtree for minimum
}

//fin_max  API TO FIND MAXIMUM NODE IN THE BINARY TREE
struct node* find_max(struct node* node) 
{
    if (node == NULL || node->right == NULL) 
    {
        return node;
    }

    return find_max(node->right); // Recursively Traverse right subtree for maximum
}
void inordertraversal(struct node* root) //Inordertraversal API that takes parent as argument and prints all elements
{
    if (root != NULL) 
    {
        inordertraversal(root->left); //Recursively traversing through left subtree first untill last left node
        printf("%d ", root->data); //printing data each time
        inordertraversal(root->right); //Recursively traversing through right subtree after left subtree
    }
}
void preorder(struct node *root) // Preorder API that prints root first then left and then right recursively
{
	if(root !=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root) //Postorder API that prints left first then right and then root recursively
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
int height(struct node *root)
{
	if(root==NULL) return 0;
	int left_height=height(root->left);
	int right_height=height(root->right);
	if(left_height > right_height) return left_height + 1;
	return right_height + 1;
}
//calculatesum API TO CALCULATE SUM OF ALL NODES IN THE TREE
int calculatesum(struct node *root)
{
        if(root==NULL) //For better practice checking if root is NULL then return 0 as sum
        {
                return 0;
        }
        return root->data+calculatesum(root->left)+calculatesum(root->right); //Recursively adding elements from the tree
}
// Delete API (handles one child, two children, and leaf node cases)
struct node* delete(struct node* node, int data)
{
    if (node == NULL) 
    {
        return node; // Node not found, do nothing
    }

    // Recursively search for the node to delete
    if (data < node->data)  //Checking if the data is lessthan the node data and recursivley deleting the data
    {
        node->left = delete(node->left, data);
    }
    else if (data > node->data) //Checking if the data is greaterthan the node data and recursivley deleting the data
    {
        node->right = delete(node->right, data);
    } 
    else 
    { // Node found
        // Handle one child or no child case
        if (node->left == NULL)
        {
            struct node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->left == NULL || node->right == NULL) 
	{
            struct node* temp;
            if (node->left == NULL) 
	    {
                temp = node->right;
            }
            else {
                temp = node->left;
            }
            free(node);
            return temp;
        }
        else {
            struct node* temp= find_min(node->right);
            node->data = temp->data;
            node->right = delete (node->right, temp->data);
        }
    }
    return node;
}

