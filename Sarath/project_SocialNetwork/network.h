#ifndef NETWORK_H
#define NETWORK_H
#include <stdbool.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_INTEREST_LENGTH 100

typedef struct User 
{
    char name[MAX_NAME_LENGTH];
    char interests[MAX_INTEREST_LENGTH];
    struct User *friends[MAX_USERS];
    int num_friends;
} User;

typedef struct Graph 
{
    User users[MAX_USERS];
    int num_users;
} Graph;

void add_user(Graph *graph, const char *name, const char *interests);
void add_friend(Graph *graph, const char *user1_name, const char *user2_name);
void search_by_name(Graph *graph, const char *name);
void search_by_interest(Graph *graph, const char *interest);
void recommend_friends(Graph *graph, const char *name);
void display_user_friends(User *user);
void display_news_feed(User *user);
bool is_friend_of_user(User *user, User *potential_friend);

#endif
