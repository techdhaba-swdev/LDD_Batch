// social_network.h

#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include<time.h>


// Define structure for user profile
//typedef struct UserProfile UserProfile;

// Define structure for user connection
//typedef struct UserConnection UserConnection;

// Structure for user profile
typedef struct UserProfile {
    char name[100];
    char interests[100];
    UserConnection* friends;
}UserProfile;

// Structure for user connection
typedef struct UserConnection {
    UserProfile* friend;
    UserConnection* next;
}UserConnection;


// Function prototypes
UserProfile* createUserProfile(const char* name, const char* interests);
void displayUserProfile(UserProfile* profile);
UserConnection* addFriend(UserProfile* user1, UserProfile* user2);
void displayFriendList(UserProfile* user);
void searchUserByName(UserProfile* root, const char* name);
void searchUserByInterest(UserProfile* root, const char* interest);
void recommendFriends(UserProfile* user);
void displayNewsFeed(UserProfile* user);

#endif /* SOCIAL_NETWORK_H */

