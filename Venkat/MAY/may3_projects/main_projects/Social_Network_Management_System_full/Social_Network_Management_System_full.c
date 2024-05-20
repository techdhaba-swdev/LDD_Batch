#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of users in the graph
#define MAX_USERS 100

// Structure to store user profile information
typedef struct UserProfile {
    char name[50]; // User's name
    char interests[100]; // User's interests
    // Other profile details can be added here
} UserProfile;

// Node structure for the adjacency list (friends list)
typedef struct UserNode {
    int userID; // Unique ID for each user
    struct UserNode *next; // Pointer to the next friend in the list
} UserNode;

// Structure to represent each user in the graph
typedef struct User {
    UserProfile profile; // User's profile
    UserNode *friendsList; // Head pointer to the user's friends list
} User;

// Graph structure to hold all users
typedef struct Graph {
    int numUsers; // Number of users currently in the graph
    User users[MAX_USERS]; // Array of users
} Graph;

// Function to create a new user profile
void createUserProfile(Graph *graph, char *name, char *interests) {
    UserProfile profile;
    strcpy(profile.name, name); // Copy the name into the profile
    strcpy(profile.interests, interests); // Copy the interests into the profile
    // Initialize other profile details here

    User newUser;
    newUser.profile = profile; // Assign the profile to the new user
    newUser.friendsList = NULL; // Initialize the friends list to NULL

    graph->users[graph->numUsers++] = newUser; // Add the new user to the graph
}

// Function to add a friend connection between two users
void addFriend(Graph *graph, int userID1, int userID2) {
    UserNode *newNode = (UserNode *)malloc(sizeof(UserNode)); // Allocate memory for a new node
    newNode->userID = userID2; // Set the userID of the new friend
    newNode->next = graph->users[userID1].friendsList; // Link the new node to the existing list
    graph->users[userID1].friendsList = newNode; // Update the head of the friends list
}

// Function to search for users by name
void searchUsersByName(Graph *graph, char *name) {
    for (int i = 0; i < graph->numUsers; i++) {
        if (strcmp(graph->users[i].profile.name, name) == 0) {
            printf("User found: %s\n", graph->users[i].profile.name);
            // Display additional user details here if needed
        }
    }
}

// Function to display a user's friend list
void displayFriends(Graph *graph, int userID) {
    UserNode *current = graph->users[userID].friendsList; // Start at the head of the friends list
    printf("Friends of %s:\n", graph->users[userID].profile.name);
    while (current != NULL) { // Traverse the list until the end
        printf("%s\n", graph->users[current->userID].profile.name); // Print each friend's name
        current = current->next; // Move to the next friend in the list
    }
}

// Main function where the program starts execution
int main() {
    Graph graph; // Create a graph instance
    graph.numUsers = 0; // Initialize the number of users to 0

    // Create user profiles
    createUserProfile(&graph, "Venkat", "Reading, Hiking");
    createUserProfile(&graph, "Bob", "Movies, Hiking");
    createUserProfile(&graph, "Rohit Sharma", "Cricket, Traveling");
    createUserProfile(&graph, "Sidharth", "Music, Gaming");

    // Add friends
    addFriend(&graph, 0, 1); // Venkat and Bob are now friends
    addFriend(&graph, 0, 2); // Venkat and Rohit Sharma are now friends
    addFriend(&graph, 0, 3); // Venkat and Sidharth are now friends

    // Search for users by name
    searchUsersByName(&graph, "Venkat");

    // Display a user's friend list
    displayFriends(&graph, 0);

    return 0; // End of the program
}
