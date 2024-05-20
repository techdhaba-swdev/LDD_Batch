#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the file system
typedef struct Node {
    char* name; // Name of the file or directory
    struct Node* firstChild; // Pointer to the first child node
    struct Node* nextSibling; // Pointer to the next sibling node
} Node;

// Function to create a new node representing a file or directory
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
    newNode->name = strdup(name); // Duplicate the name for the node
    newNode->firstChild = NULL; // Initialize the first child to NULL
    newNode->nextSibling = NULL; // Initialize the next sibling to NULL
    return newNode; // Return the newly created node
}

// Function to add a child node to a parent node
void addChildNode(Node* parent, Node* child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child; // If no child, add as first child
    } else {
        Node* current = parent->firstChild;
        // Traverse siblings until the last one
        while (current->nextSibling != NULL) {
            current = current->nextSibling;
        }
        current->nextSibling = child; // Add new child as the next sibling of the last child
    }
}

// Function to list the contents of a directory
void listDirectoryContents(Node* directory) {
    Node* current = directory->firstChild;
    // Loop through each child node and print its name
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->nextSibling;
    }
}

// Function to navigate to a subdirectory given its name
Node* navigateToSubdirectory(Node* currentDirectory, const char* subdirectoryName) {
    Node* current = currentDirectory->firstChild;
    // Loop through each child node to find the subdirectory
    while (current != NULL) {
        if (strcmp(current->name, subdirectoryName) == 0) {
            return current; // Return the subdirectory node if found
        }
        current = current->nextSibling;
    }
    return NULL; // Return NULL if subdirectory not found
}

// Function to delete a node and all its children recursively
void deleteNode(Node* node) {
    if (node == NULL) {
        return; // If node is NULL, nothing to delete
    }
    Node* current = node->firstChild;
    // Recursively delete all children
    while (current != NULL) {
        Node* next = current->nextSibling;
        deleteNode(current);
        current = next;
    }
    free(node->name); // Free the memory allocated for the node's name
    free(node); // Free the memory allocated for the node itself
}

// Helper function to search for a file by name and track the path
Node* searchFileHelper(Node* directory, const char* fileName, char* path, int depth) {
    if (directory == NULL) {
        return NULL; // If directory is NULL, file not found
    }
    // Append the current directory's name to the path if not root
    if (depth > 0) {
        strcat(path, "/");
        strcat(path, directory->name);
    }
    // Check if the current node is the file we're looking for
    if (strcmp(directory->name, fileName) == 0) {
        return directory; // Return the file node if found
    }
    Node* current = directory->firstChild;
    // Recursively search in each child
    while (current != NULL) {
        char* newPath = strdup(path); // Duplicate path for recursive call
        Node* found = searchFileHelper(current, fileName, newPath, depth + 1);
        if (found != NULL) {
            // If file is found, copy the path to the original path variable
            strcpy(path, newPath);
            free(newPath);
            return found;
        }
        free(newPath); // Free the duplicated path if not found
        current = current->nextSibling;
    }
    return NULL; // Return NULL if file not found in any child
}

// Function to search for a file by name
Node* searchFile(Node* directory, const char* fileName) {
    char* path = strdup(""); // Initialize path as empty string
    Node* found = searchFileHelper(directory, fileName, path, 0);
    if (found != NULL) {
        // If file is found, print the path
        printf("File '%s' found at path: %s\n", fileName, path);
    } else {
        // If file is not found, print not found message
        printf("File '%s' not found.\n", fileName);
    }
    free(path); // Free the path memory
    return found; // Return the found file node or NULL
}

// Main function where the file system is created and operations are performed
int main() {
    // Create the root of the file system
    Node* root = createNode("/");

    // Add directories and files to the root
    addChildNode(root, createNode("dir1"));
    addChildNode(root, createNode("file1.txt"));
    addChildNode(root, createNode("dir2"));

    // Add files to dir1
    Node* dir1 = navigateToSubdirectory(root, "dir1");
    addChildNode(dir1, createNode("file2.txt"));
    addChildNode(dir1, createNode("file3.txt"));

    // Add files to dir2
    Node* dir2 = navigateToSubdirectory(root, "dir2");
    addChildNode(dir2, createNode("file4.txt"));
    addChildNode(dir2, createNode("file5.txt"));

    // Print the contents of the root directory
    printf("Contents of root directory:\n");
    listDirectoryContents(root);

    // Print the contents of dir1
    printf("\nContents of dir1:\n");
    listDirectoryContents(dir1);

    // Print the contents of dir2
    printf("\nContents of dir2:\n");
    listDirectoryContents(dir2);

    // Search for a specific file
    searchFile(root, "file5.txt");

    // Clean up memory by deleting all nodes
    deleteNode(root);

    return 0;
}
