#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <pthread.h>
#include <string.h>

// Callback function
typedef void (*callback_p)(const char *c_path, int actions);

// Structure to hold callback information
typedef struct {
    const char *c_path; // Path for the callback
    int actions;
    callback_p callback; // Pointer to the callback function
} CallbackInfo;

// variables
int inotify_fd; // File descriptor for inotify
pthread_mutex_t lock;
CallbackInfo callbacks[36]; // Array to store callback information
size_t num_callbacks = 0; // Number of registered callbacks

// Function to register a callback for a specific file or directory
void register_callback(const char *c_path, int actions, callback_p callback) {
    pthread_mutex_lock(&lock);

    // Adding the watch to the inotify
    int watch_fd = inotify_add_watch(inotify_fd, c_path, actions);
    if (watch_fd < 0) {
        perror("inotify_add_watch");
        exit(EXIT_FAILURE);
    }

    // Storing the callback information
    callbacks[num_callbacks].c_path = c_path;
    callbacks[num_callbacks].actions = actions;
    callbacks[num_callbacks].callback = callback;
    num_callbacks++;

    pthread_mutex_unlock(&lock);
}

// Function to monitor the inotify
void *monitor_thread(void *arg) {
    char buffer[4096]; // Buffer to read actions from inotify
    ssize_t bytes_read;

    // Continuously read action from inotify
    while ((bytes_read = read(inotify_fd, buffer, sizeof(buffer))) > 0) {
        // Process each action in the buffer
        for (char *ptr = buffer; ptr < buffer + bytes_read;) {
            struct inotify_event *event = (struct inotify_event *)ptr;

            pthread_mutex_lock(&lock);

            // Iterate through registered callbacks
            for (size_t i = 0; i < num_callbacks; i++) {
                if (strcmp(callbacks[i].c_path, event->name) == 0 && (callbacks[i].actions & event->mask)) {
                    // Call the registered callback function
                    callbacks[i].callback(event->name, event->mask);
                }
            }

            pthread_mutex_unlock(&lock);

            // Move to the next action in the buffer
            ptr += sizeof(struct inotify_event) + event->len;
        }
    }

    return NULL;
}

void my_callback(const char *c_path, int actions) {
    printf("File %s was modified\n", c_path);
}

void my_other_callback(const char *c_path, int actions) {
    printf("Event occurred in directory %s\n", c_path);
}

int main(int argc, char *argv[]) {
    // Initialize the inotify
    inotify_fd = inotify_init();
    if (inotify_fd < 0) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_init(&lock, NULL);

    // Register callbacks for specific file or directory
    register_callback("/path/to/file", IN_MODIFY, my_callback);
    register_callback("/path/to/directory", IN_CREATE | IN_DELETE, my_other_callback);

    // Start the monitor thread
    pthread_t thread;
    if (pthread_create(&thread, NULL, monitor_thread, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Additional tasks or functionality can be performed here while the monitor thread runs

    // Clean up and exit
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }
    close(inotify_fd); // Close the inotify file descriptor
    pthread_mutex_destroy(&lock); // Destroy the mutex lock

    return 0;
}


