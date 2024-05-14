#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/inotify.h>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (1024 * (EVENT_SIZE + 16))

typedef struct {
    char *path;
    void (*callback)(const char *path, int event); // Corrected callback declaration
} CallbackInfo;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    CallbackInfo *callbacks;
    int size;
} CallbackList;

CallbackList callback_list;

void *monitor_changes(void *arg) {
    int fd;
    int wd;
    char buf[BUF_LEN];
    int len;
    struct inotify_event *event;

    fd = inotify_init();
    if (fd == -1) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < callback_list.size; ++i) {
        wd = inotify_add_watch(fd, callback_list.callbacks[i].path, IN_MODIFY | IN_CREATE | IN_DELETE);
        if (wd == -1) {
            perror("inotify_add_watch");
            exit(EXIT_FAILURE);
        }
    }
    pthread_mutex_unlock(&mutex);

    while (1) {
        len = read(fd, buf, BUF_LEN);
        if (len == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        for (char *ptr = buf; ptr < buf + len; ptr += sizeof(struct inotify_event) + event->len) {
            event = (struct inotify_event *)ptr;

            pthread_mutex_lock(&mutex);
            for (int i = 0; i < callback_list.size; ++i) {
                if (strcmp(callback_list.callbacks[i].path, event->name) == 0) {
                    callback_list.callbacks[i].callback(event->name, event->mask);
                }
            }
            pthread_mutex_unlock(&mutex);
        }
    }

    close(fd);
}

void register_callback(const char *path, void (*callback)(const char *path, int event)) {
    pthread_mutex_lock(&mutex);
    callback_list.callbacks = realloc(callback_list.callbacks, (callback_list.size + 1) * sizeof(CallbackInfo));
    if (callback_list.callbacks == NULL) {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    callback_list.callbacks[callback_list.size].path = strdup(path);
    callback_list.callbacks[callback_list.size].callback = callback;
    callback_list.size++;
    pthread_mutex_unlock(&mutex);
}

void example_callback(const char *path, int event) {
    printf("File %s was ", path);
    if (event & IN_CREATE) {
        printf("created. ");
    }
    if (event & IN_DELETE) {
        printf("deleted. ");
    }
    if (event & IN_MODIFY) {
        printf("modified. ");
    }
    printf("\n");
}

int main() {
    callback_list.callbacks = NULL;
    callback_list.size = 0;

    pthread_t thread;
    pthread_create(&thread, NULL, monitor_changes, NULL);

    register_callback("/path/to/file", example_callback);

    pthread_join(thread, NULL);

    for (int i = 0; i < callback_list.size; ++i) {
        free(callback_list.callbacks[i].path);
    }
    free(callback_list.callbacks);

    return 0;
}



