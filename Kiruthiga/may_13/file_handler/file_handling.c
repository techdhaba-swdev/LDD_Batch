#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/inotify.h>

#define MAX_EVENTS 1024
#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (MAX_EVENTS * (EVENT_SIZE + 16))

void handle_event(int fd, char *target_file) {
    ssize_t len;
    char buf[BUF_LEN] __attribute__((aligned(4)));

    len = read(fd, buf, BUF_LEN);
    if (len == -1 && errno != EAGAIN) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    for (char *ptr = buf; ptr < buf + len;) {
        struct inotify_event *event = (struct inotify_event *)ptr;
        if (event->len && strcmp(event->name, target_file) == 0) {
            printf("File %s was %s\n", target_file,
                   event->mask & IN_MODIFY ? "modified" :
                   event->mask & IN_CREATE ? "created" :
                   event->mask & IN_DELETE ? "deleted" : "unknown");
        }
        ptr += sizeof(struct inotify_event) + event->len;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file/directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target_file = argv[1];
    int inotify_fd = inotify_init();
    if (inotify_fd == -1) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    int wd = inotify_add_watch(inotify_fd, target_file,
                               IN_MODIFY | IN_CREATE | IN_DELETE);
    if (wd == -1) {
        perror("inotify_add_watch");
        exit(EXIT_FAILURE);
    }

    printf("Watching file/directory: %s\n", target_file);

    while (1) {
        handle_event(inotify_fd, target_file);
    }

    close(inotify_fd);

    return 0;
}


