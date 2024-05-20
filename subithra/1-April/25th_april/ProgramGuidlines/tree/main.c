#include <stdio.h> // Include standard input/output header for printf and scanf functions
#include "main.h" // Include the header file containing tree functions and structure in mail header file
		  //
int main() {//The main function, which serves as the entry point of the program.
struct TreeNode* root = NULL; // Declares a pointer root of type struct TreeNode* and initializes it to NULL. This pointer will serve as the root of the binary tree 
 int choice, data;//Declares two variables choice and data to store user input for menu choice and node data, respectively.
  // Start of the main program loop
    while (1) {//Starts an infinite loop, which will continue until explicitly exited.
        printf("\nBinary Tree Operations:\n"); // Prints a menu of available binary tree operations and prompts the user to enter their choice.
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); //Reads the user's choice from the standard input and stores it in the variable choice.

        // Switch statement to handle user's choice
        switch (choice) {//Starts a switch statement based on the value of choice. It allows different actions to be taken based on the user's input.

            case 1://Handles the case where the user chooses to insert a node into the binary tree.
                printf("Enter data to insert: ");//Prompts the user to enter the data for the new node to be inserted.
                if (scanf("%d", &data) != 1) { // Checks if the input operation succeeded. If it fails (i.e., the return value of scanf is not 1, indicating failure to read an integer), it indicates invalid input.
                    printf("Error: Invalid input\n"); // Print error message if input is not an integer
                    break;
                }
                root = insertNode(root, data); // Calls the insertNode function with the current root and the data entered by the user. Updates the root of the tree with the returned value, which may be the same or modified root.
                break;
            case 2://Handles the case where the user chooses to perform an inorder traversal of the binary tree.
                printf("Inorder Traversal: ");//rints a message indicating that the inorder traversal is being performed.
                inorderTraversal(root);// Calls the inorderTraversal function with the current root of the tree, which prints the nodes of the tree in inorder traversal order.
                printf("\n");
                break;//Breaks out of the current case in the switch statement.
            case 3://Handles the case where the user chooses to exit the program.
                printf("Exiting program\n");//Prints a message indicating that the program is exiting and returns 0 to the operating system, indicating successful termination of the program.
                return 0; // Exit the program
            default://Handles the default case, which occurs when the user enters an invalid choice.
                printf("Invalid choice. Please try again.\n"); // Prints a message informing the user of an invalid choice and prompting them to try again.

        }
    }

    return 0; // Return from the main function
}
