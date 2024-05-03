#include "profile.h"
UserProfile* searchUser(const char* name, UserProfile* profiles[]) { // Function to search for a user by name.
    for (int i = 0; i < 26; i++) { // Looping through each index of the profiles array.
        UserProfile* current = profiles[i]; // Getting the current profile.
        while (current != NULL) { // Looping through each user profile at the current index.
            if (strcmp(current->name, name) == 0) { // Comparing the name of the current profile with the given name.
                return current; // Returning the current profile if found.
            }
            current = current->next; // Moving to the next profile.
        }
    }
    return NULL; // Returning NULL if the user is not found.
}
