#include "AddFriend.h"
#include <stdlib.h>

// Function to add a friend connection between two users.
void addFriend(Graph *graph, int userID1, int userID2) {
    UserNode *newNode = (UserNode *)malloc(sizeof(UserNode)); // Allocate memory for a new node.
    newNode->userID = userID2; // Set the userID of the new friend.
    newNode->next = graph->users[userID1].friendsList; // Link the new node to the existing list.
    graph->users[userID1].friendsList = newNode; // Update the head of the friends list.
}
