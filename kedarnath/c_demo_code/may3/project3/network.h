// social_network.h

#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<time.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_INTEREST_LENGTH 100


typedef struct User {
    char name[MAX_NAME_LENGTH];
    char interests[MAX_INTEREST_LENGTH];
    struct User* friends[MAX_USERS];
    int num_friends;
} User;

typedef struct Graph {
    User users[MAX_USERS];
    int num_users;
} Graph; 

void add_user(Graph* graph, const char* name, const char* interests);
bool are_friends(User* user1, User* user2);
void add_friendship(Graph* graph, const char* user1_name, const char* user2_name);
void search_users_by_name(Graph* graph, const char* name);
void search_users_by_interest(Graph* graph, const char* interest);
void recommend_friends(Graph* graph, const char* name);



#endif /* SOCIAL_NETWORK_H */

