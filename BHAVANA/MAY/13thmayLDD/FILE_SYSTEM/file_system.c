#include "fs_notifier.h" // Including the header file for the file system notifier functions
#include <stdio.h> // Including standard input/output functions
#include <stdlib.h> // Including standard library functions
#include <unistd.h> // Including POSIX operating system API functions
#include <sys/inotify.h> // Including inotify API for file system monitoring

#define EVENT_SIZE  (sizeof(struct inotify_event)) // Defining the size of inotify_event structure
#define BUF_LEN     (1024 * (EVENT_SIZE + 16)) // Defining the size of the read buffer

static int fd; // File descriptor for inotify instance
static int wd; // Watch descriptor for the watched directory

int init_fs_notifier(const char *directory) { // Function to initialize the file system notifier
    fd = inotify_init(); // Initializing inotify instance
    if (fd < 0) { // Checking for initialization failure
        perror("inotify_init"); // Printing error message if initialization fails
        return -1; // Returning failure status
    }

    wd = inotify_add_watch(fd, directory, IN_MODIFY | IN_CREATE | IN_DELETE); // Adding directory to watch list
    if (wd < 0) { // Checking for watch addition failure
        perror("inotify_add_watch"); // Printing error message if watch addition fails
        return -1; // Returning failure status
    }

    printf("Watching directory: %s\n", directory); // Printing message indicating directory is being watched
    return 0; // Returning success status
}

void start_fs_monitoring() { // Function to start monitoring the file system
    char buffer[BUF_LEN]; // Buffer to read inotify events
    int length; // Length of read data

    while (1) { // Infinite loop for continuous monitoring
        length = read(fd, buffer, BUF_LEN); // Reading inotify events
        if (length < 0) { // Checking for read failure
            perror("read"); // Printing error message if read fails
            exit(EXIT_FAILURE); // Exiting the program with failure status
        }

        struct inotify_event *event = (struct inotify_event *) &buffer; // Pointer to inotify event structure
        if (event->len) { // Checking if event contains valid data
            if (event->mask & IN_CREATE) { // Checking if file or directory created
                printf("New file or directory created: %s\n", event->name); // Printing message for creation event
            } else if (event->mask & IN_DELETE) { // Checking if file or directory deleted
                printf("File or directory deleted: %s\n", event->name); // Printing message for deletion event
            } else if (event->mask & IN_MODIFY) { // Checking if file or directory modified
                printf("File or directory modified: %s\n", event->name); // Printing message for modification event
            }
        }
    }
}

void stop_fs_monitoring() { // Function to stop monitoring the file system
    if (fd >= 0) { // Checking if inotify instance is valid
        close(fd); // Closing inotify instance
    }
}
