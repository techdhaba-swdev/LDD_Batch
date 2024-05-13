#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <errno.h>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define EVENT_BUF_LEN (1024 * (EVENT_SIZE + 16))

typedef void (*NotificationCallback)(const char *path, unsigned int event_mask);

typedef struct {
    int wd;
    char *path;
    NotificationCallback callback;
} WatchEntry;

static int inotify_fd;
static WatchEntry *watches = NULL;
static int num_watches = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static volatile int keep_running = 1;

void handle_signal(int signal) {
    keep_running = 0;
}

void example_callback(const char *path, unsigned int event_mask) {
    if (event_mask & IN_CREATE) {
        printf("A new file was added to %s\n", path);
    } else if (event_mask & IN_DELETE) {
        printf("A file was deleted from %s\n", path);
    } else if (event_mask & IN_MODIFY) {
        printf("A file was modified in %s\n", path);
    }
}

void register_watch(const char *path, NotificationCallback callback) {
    pthread_mutex_lock(&mutex);

    int wd = inotify_add_watch(inotify_fd, path, IN_MODIFY | IN_CREATE | IN_DELETE);
    if (wd == -1) {
        perror("inotify_add_watch");
        pthread_mutex_unlock(&mutex);
        return;
    }

    WatchEntry entry = {wd, strdup(path), callback};
    WatchEntry *temp_watches = realloc(watches, (num_watches + 1) * sizeof(WatchEntry));
    if (!temp_watches) {
        perror("realloc");
        free(entry.path); // Free the duplicated path to prevent memory leak
        pthread_mutex_unlock(&mutex);
        return;
    } else {
        watches = temp_watches;
        watches[num_watches++] = entry;
    }

    pthread_mutex_unlock(&mutex);
}

void *monitor_thread(void *arg) {
    char buf[EVENT_BUF_LEN];
    while (keep_running) {
        ssize_t len = read(inotify_fd, buf, EVENT_BUF_LEN);
        if (len == -1 && errno != EINTR) {
            perror("read");
            continue;
        }

        char *ptr = buf;
        while (len > 0) {
            struct inotify_event *event = (struct inotify_event *)ptr;

            pthread_mutex_lock(&mutex);
            for (int i = 0; i < num_watches; i++) {
                if (watches[i].wd == event->wd) {
                    watches[i].callback(watches[i].path, event->mask);
                }
            }
            pthread_mutex_unlock(&mutex);

            ptr += EVENT_SIZE + event->len;
            len -= EVENT_SIZE + event->len;
        }
    }

    return NULL;
}

void cleanup() {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < num_watches; i++) {
        inotify_rm_watch(inotify_fd, watches[i].wd);
        free(watches[i].path);
    }
    free(watches);
    watches = NULL;
    num_watches = 0;
    pthread_mutex_unlock(&mutex);
    close(inotify_fd);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    inotify_fd = inotify_init();
    if (inotify_fd == -1) {
        perror("inotify_init");
        return 1;
    }

    pthread_t thread;
    if (pthread_create(&thread, NULL, monitor_thread, NULL) != 0) {
        perror("pthread_create");
        close(inotify_fd);
        return 1;
    }

    // Register watches and callbacks here
    register_watch("/home/rps/Desktop/code", example_callback);

    while (keep_running) {
        sleep(1);
    }

    cleanup();
    pthread_join(thread, NULL);
    return 0;
}
