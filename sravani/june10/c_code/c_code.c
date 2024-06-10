#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    struct Student* left;
    struct Student* right;
};

struct Student* createStudent(int id, const char* name) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent != NULL) {
        newStudent->id = id;
        strcpy(newStudent->name, name); 
        newStudent->left = NULL;
        newStudent->right = NULL;
    }
    return newStudent;
}

struct Student* addStudent(struct Student* root, int id, const char* name) {
    if (root == NULL) {
        return createStudent(id, name);
    }

    if (id < root->id) {
        root->left = addStudent(root->left, id, name);
    } else if (id > root->id) {
        root->right = addStudent(root->right, id, name);
    }

    return root;
}

struct Student* searchStudent(struct Student* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }

    if (id < root->id) {
        return searchStudent(root->left, id);
    } else {
        return searchStudent(root->right, id);
    }
}

struct Student* findMin(struct Student* node) {
    struct Student* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Student* deleteStudent(struct Student* root, int id) {
    if (root == NULL) {
        return root;
    }

    if (id < root->id) {
        root->left = deleteStudent(root->left, id);
    } else if (id > root->id) {
        root->right = deleteStudent(root->right, id);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Student* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Student* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Student* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->id = temp->id;
        strcpy(root->name, temp->name); // Directly copy the string

        // Delete the inorder successor
        root->right = deleteStudent(root->right, temp->id);
    }
    return root;
}

void printStudentsInOrder(struct Student* root) {
    if (root != NULL) {
        printStudentsInOrder(root->left);
        printf("ID: %d, Name: %s\n", root->id, root->name);
        printStudentsInOrder(root->right);
    }
}

void freeStudents(struct Student* root) {
    if (root != NULL) {
        freeStudents(root->left);
        freeStudents(root->right);
        free(root);
    }
}

int main() {
    struct Student* root = NULL;

    root = addStudent(root, 1, "Sravani");
    root = addStudent(root, 2, "Dhriti");
    root = addStudent(root, 3,"techdhaba");

    printf("List of students:\n");
    printStudentsInOrder(root);
    printf("\n");

    int searchId =3;
    struct Student* searchedStudent = searchStudent(root, searchId);
    if (searchedStudent != NULL) {
        printf("Found student with ID %d: %s\n", searchId, searchedStudent->name);
    } else {
        printf("Student with ID %d not found.\n", searchId);
    }

    int deleteId = 1;
    root = deleteStudent(root, deleteId);
    printf("Deleted student with ID %d.\n", deleteId);

    printf("Updated list of students:\n");
    printStudentsInOrder(root);

    freeStudents(root);

    return 0;
}
