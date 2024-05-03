#include "profile.h"
void displayFriendList(GraphNode* friends) { // Function to display a user's friend list.
    while (friends != NULL) { // Looping through each friend in the friend list.
        printf("%s\n", friends->profile->name); // Printing the name of the current friend.
        friends = friends->next; // Moving to the next friend in the list.
    }
}

