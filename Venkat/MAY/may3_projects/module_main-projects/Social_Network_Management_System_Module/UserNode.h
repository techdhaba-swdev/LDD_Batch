#ifndef USERNODE_H
#define USERNODE_H

// Node structure for the adjacency list (friends list).
typedef struct UserNode {
    int userID; // Unique ID for each user.
    struct UserNode *next; // Pointer to the next friend in the list.
} UserNode;

#endif // USERNODE_H
