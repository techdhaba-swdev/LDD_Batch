/*Question:

Design and implement a data structure in C that efficiently stores and retrieves student information for a university. The data structure should handle the following operations:

Add a new student record
Search for a student by ID
Delete a student record by ID
Print a list of all students, sorted by name (ascending order)
Consider factors like memory efficiency, average case performance for each operation, and potential edge cases (e.g., duplicate IDs).

Explanation:

This question assesses your understanding of choosing the appropriate data structure (e.g., hash table for fast lookups by ID, self-balancing binary search tree for sorted name list) and implementing it effectively in C. It also encourages you to think about handling edge cases and optimizing performance.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student
typedef struct {
    int id;
    char name[50];
    // Add other relevant student information here
} Student;

// Define a node structure for the binary search tree
typedef struct TreeNode {
    Student data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new student node
TreeNode* createStudentNode(int id, const char* name) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));//allocates a memory for a new treenode 
    if (newNode != NULL) {
        //intialize the student data
        newNode->data.id = id;
        strcpy(newNode->data.name, name);//string copy from source to destination 
        //intialize the left and right pointers
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to insert a student record into the binary search tree
TreeNode* insertStudent(TreeNode* root, int id, const char* name) {
    //if the tree is empty,create a new node and return it as the root 
    if (root == NULL) {
        return createStudentNode(id, name);
    }
    //if the id is less than the roots id , insert into the left subtree
    if (id < root->data.id) {
        root->left = insertStudent(root->left, id, name);
    }//if the id is greater than the roots id,insert the right subtree
    else if (id > root->data.id) {
        root->right = insertStudent(root->right, id, name);
    }
    return root;
}

// Function to search for a student by ID in the binary search tree
TreeNode* searchStudent(TreeNode* root, int id) {
    //if the tree is empty or the roots id matches the target id, return the root 
    if (root == NULL || root->data.id == id) {
        return root;
    }
    //if the target id is less than the roots id,search in the left subtree
    if (id < root->data.id) {
        return searchStudent(root->left, id);
    } else {//otherwise search in the right subtree 
        return searchStudent(root->right, id);
    }
}

// Function to find the minimum node (leftmost) in a binary search tree
TreeNode* findMin(TreeNode* node) {
   //traverse left until the leftmost node is reached 
    while (node->left != NULL) { 
        node = node->left;
    }
    return node;
}

// Function to delete a student record by ID from the binary search tree
TreeNode* deleteStudent(TreeNode* root, int id) {
    //if the tree is empty, return null
    if (root == NULL) {
        return root;
    }
    //if the target id is less than the roots id, delete from the left subtree
    if (id < root->data.id) {
        root->left = deleteStudent(root->left, id);
    } else if (id > root->data.id) {//if the target id is grester thann the roots id,delete from the right subtree 
        root->right = deleteStudent(root->right, id);
    } else { // if the target is found 
        // Case 1: No child or only one child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // Case 2: Two children
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteStudent(root->right, temp->data.id);
    }
    return root;
}

// Function to print student records sorted by name (inorder traversal)
void printStudentsInOrder(TreeNode* root) {
    if (root != NULL) {//if root is null, return 
        printStudentsInOrder(root->left);//recursively print the left subtree 
        printf("ID: %d, Name: %s\n", root->data.id, root->data.name);//print the current student id and name 
        printStudentsInOrder(root->right);//recursively print the right subtree 
    }
}

int main() {
    TreeNode* root = NULL;

    // insert some records for student 
    root = insertStudent(root, 101, "litheef");
    root = insertStudent(root, 102, "sudher");
    root = insertStudent(root, 103, "sandeep");

    printf("Student records:\n");//print all student recorrrrds in sorted order 
    printStudentsInOrder(root);

    TreeNode* student = searchStudent(root, 102);//search for a student by id 
    if (student != NULL) {
        printf("\nStudent found - ID: %d, Name: %s\n", student->data.id, student->data.name);
    } else {
        printf("\nStudent not found.\n");
    }

    root = deleteStudent(root, 102);//delete the student record by id 
    printf("\nAfter deleting student with ID 102:\n");
    printStudentsInOrder(root);

    return 0;
}
