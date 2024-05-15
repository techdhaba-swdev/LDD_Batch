#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/inotify.h>
#include <pthread.h>

#define MAX_EVENTS 1024
#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (MAX_EVENTS * (EVENT_SIZE + 16))

typedef enum {
    MODIFICATION = 1,
    CREATION = 2,
    DELETION = 4
} NotificationType;

typedef struct {
    int fd;
    int wd;
    char* path;
    NotificationType type;
    void (*callback)(const char*, NotificationType);
} WatchDescriptor;

WatchDescriptor* watches[MAX_EVENTS]; // Array to store watch descriptors
pthread_mutex_t watches_mutex = PTHREAD_MUTEX_INITIALIZER;

void handle_events(int fd) {
    char buf[BUF_LEN];
    int len, i = 0;
    struct inotify_event *event;

    len = read(fd, buf, BUF_LEN);
    if (len == -1 && errno != EAGAIN) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    while (i < len) {
        event = (struct inotify_event *)&buf[i];
        for (int j = 0; j < MAX_EVENTS; j++) {
            if (watches[j] != NULL && watches[j]->wd == event->wd) {
                watches[j]->callback(event->name, event->mask);
                break;
            }
        }
        i += EVENT_SIZE + event->len;
    }
}

void* watch_thread(void* arg) {
    int fd = inotify_init();
    if (fd == -1) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    while (1) {
        handle_events(fd);
    }
    close(fd);
}

int add_watch(const char* path, NotificationType type, void (*callback)(const char*, NotificationType)) {
    int wd = inotify_add_watch(watches[0]->fd, path, IN_MODIFY | IN_CREATE | IN_DELETE);
    if (wd == -1) {
        perror("inotify_add_watch");
        exit(EXIT_FAILURE);
    }

    WatchDescriptor* watch = (WatchDescriptor*)malloc(sizeof(WatchDescriptor));
    watch->fd = watches[0]->fd;
    watch->wd = wd;
    watch->path = strdup(path);
    watch->type = type;
    watch->callback = callback;

    pthread_mutex_lock(&watches_mutex);
    for (int i = 0; i < MAX_EVENTS; i++) {
        if (watches[i] == NULL) {
            watches[i] = watch;
            pthread_mutex_unlock(&watches_mutex);
            return wd;
        }
    }
    pthread_mutex_unlock(&watches_mutex);
    return -1; // Max watches reached
}

void dummy_callback(const char* path, NotificationType type) {
    printf("Change detected in %s\n", path);
    switch (type) {
        case MODIFICATION:
            printf("File modified\n");
            break;
        case CREATION:
            printf("File created\n");
            break;
        case DELETION:
            printf("File deleted\n");
            break;
    }
}

int main() {
    pthread_t tid;
    watches[0] = (WatchDescriptor*)malloc(sizeof(WatchDescriptor));
    watches[0]->fd = inotify_init();
    if (pthread_create(&tid, NULL, watch_thread, NULL)) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    add_watch("/path/to/watch", MODIFICATION | CREATION | DELETION, dummy_callback);

    pthread_join(tid, NULL);
    return 0;
}
