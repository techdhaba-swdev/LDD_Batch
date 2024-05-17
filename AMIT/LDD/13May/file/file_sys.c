#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void (*callback)(const char* path, int event_type);
// Listener structure
typedef struct {
    char path[256]; // File/directory path
    int event_types; // Bitmask for event types (e.g., modification, creation, deletion)
    void (*callback)(const char* path, int event_type); // Callback function
} Listener;

// Register a listener
void register_listener(Listener* listener) {
    // Add listener to your data structure (e.g., hash table)
   printf("Registered listener for %s (Events: %d)\n", listener->path, listener->event_types);
}

// Simulate an event (for demonstration purposes)
void simulate_event(const char* path, int event_type) {
    printf("Event: %s (%d)\n", path, event_type);
}

int main() {
    // Example usage
    Listener my_listener;
    strcpy(my_listener.path, "/path/to/myfile.txt");
    my_listener.event_types = 1|2|4; // Assume 1 for modification,2 for creation ,4 for deletion events
    my_listener.callback = simulate_event;

    // Register the listener
    register_listener(&my_listener);

    // Simulate an event (e.g., file modified)
    my_listener.callback(my_listener.path, 1);//modify event 
    my_listener.callback(my_listener.path, 2);//creation event 
    my_listener.callback(my_listener.path, 4);//deletion event
    return 0;

}
