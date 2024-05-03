#ifndef PROFILE_H
#define PROFILE_H
#include "header.h"
#define MAX_NAME_LENGTH 50 // Defining maximum length for user name.
#define MAX_INTERESTS_LENGTH 100 // Defining maximum length for user interests.

typedef struct UserProfile { // Defining structure for user profile.
    char name[MAX_NAME_LENGTH]; // Character array to store user name.
    char interests[MAX_INTERESTS_LENGTH]; // Character array to store user interests.
    struct UserProfile* next; // Pointer to next user profile.
} UserProfile;

typedef struct GraphNode { // Defining structure for a node in the user graph.
    UserProfile* profile; // Pointer to user profile.
    struct GraphNode* next; // Pointer to next graph node.
} GraphNode;
UserProfile* createProfile(const char* name, const char* interests);
void addFriend(GraphNode* graph[], UserProfile* user1, UserProfile* user2);
UserProfile* searchUser(const char* name, UserProfile* profiles[]);
void displayFriendList(GraphNode* friends);
void freeMemory(UserProfile* profiles[], GraphNode* graph[]);

#endif
