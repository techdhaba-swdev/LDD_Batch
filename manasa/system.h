#ifndef SYSTEM_H
#define SYSTEM_H

#define MAX_NAME_LENGTH 50
#define MAX_INTEREST_LENGTH 100

// Structure for a user profile
struct UserProfile {
    char name[MAX_NAME_LENGTH];
    char interests[MAX_INTEREST_LENGTH];
    struct UserProfile *next;
};

typedef struct UserProfile UserProfile;

// Structure for a graph node
struct GraphNode {
    int userId;
    UserProfile *profile;
    struct GraphNode *next;
    struct FriendNode *friends;
};

typedef struct GraphNode GraphNode;

// Structure for a friend node
struct FriendNode {
    GraphNode *user;
    struct FriendNode *next;
};

typedef struct FriendNode FriendNode;

// Function declarations
void createUserProfile(GraphNode **graph, char *name, char *interests);
void addFriend(GraphNode *user1, GraphNode *user2);
GraphNode* searchUserByName(GraphNode *graph, char *name);
void recommendFriends(GraphNode *graph, char *name);
void displayFriendList(GraphNode *user);
void displayNewsFeed(GraphNode *user);

#endif /* SYSTEM_H */
