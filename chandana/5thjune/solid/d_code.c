#include <stdio.h>

typedef struct {
    const char* (*getMessage)(void);
} Message;

const char* getEmailMessage() {
    return "You've got mail!";
}

typedef struct {
    Message* message;
} Notification;

void notify(const Notification* notification) {
    printf("%s\n", notification->message->getMessage());
}

int main() {
    Message email = { getEmailMessage };
    Notification notification = { &email };
    notify(&notification);
    return 0;
}
