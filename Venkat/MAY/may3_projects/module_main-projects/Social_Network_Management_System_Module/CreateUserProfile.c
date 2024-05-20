#include "CreateUserProfile.h"
#include <string.h>
#include <stddef.h>

// Function to create a new user profile.
void createUserProfile(Graph *graph, char *name, char *interests) {
    UserProfile profile;
    strcpy(profile.name, name); // Copy the name into the profile.
    strcpy(profile.interests, interests); // Copy the interests into the profile.
    // Initialize other profile details here.

    User newUser;
    newUser.profile = profile; // Assign the profile to the new user.
    newUser.friendsList = NULL; // Initialize the friends list to NULL.

    graph->users[graph->numUsers++] = newUser; // Add the new user to the graph.
}


