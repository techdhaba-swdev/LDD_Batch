#ifndef USER_H
#define USER_H

#include "UserProfile.h"
#include "UserNode.h"

// Structure to represent each user in the graph.
typedef struct User {
    UserProfile profile; // User's profile.
    UserNode *friendsList; // Head pointer to the user's friends list.
} User;

#endif // USER_H
