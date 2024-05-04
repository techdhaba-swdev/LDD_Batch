#include "DisplayFriends.h"
#include <stdio.h>
#include <stddef.h>
// Function to display a user's friend list.
void displayFriends(Graph *graph, int userID) {
    UserNode *current = graph->users[userID].friendsList; // Start at the head of the friends list.
    printf("Friends of %s:\n", graph->users[userID].profile.name);
    while (current != NULL) { // Traverse the list until the end.
        printf("%s\n", graph->users[current->userID].profile.name); // Print each friend's name.
        current = current->next; // Move to the next friend in the list.
    }
}


