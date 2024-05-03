#include "profile.h"
UserProfile* createProfile(const char* name, const char* interests) { // Function to create a new user profile.
    UserProfile* newUser = (UserProfile*)malloc(sizeof(UserProfile)); // Allocating memory for user profile.
    if (newUser != NULL) { // Checking if memory allocation is successful.
        strncpy(newUser->name, name, MAX_NAME_LENGTH - 1); // Safely copying user name to profile.
        newUser->name[MAX_NAME_LENGTH - 1] = '\0'; // Null-terminating the user name.
        strncpy(newUser->interests, interests, MAX_INTERESTS_LENGTH - 1); // Safely copying user interests to profile.
        newUser->interests[MAX_INTERESTS_LENGTH - 1] = '\0'; // Null-terminating the user interests.
        newUser->next = NULL; // Initializing next pointer to NULL.
    }
    return newUser; // Returning pointer to the newly created user profile.
}
