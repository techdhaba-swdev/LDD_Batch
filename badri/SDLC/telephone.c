#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char number[15];
};

struct PhoneDirectory {
    struct Contact contacts[MAX_CONTACTS];
    int count;
};

void add_contact(struct PhoneDirectory *directory, char *name, char *number) {
    if (directory->count < MAX_CONTACTS) {
        strcpy(directory->contacts[directory->count].name, name);
        strcpy(directory->contacts[directory->count].number, number);
        directory->count++;
        printf("Contact added successfully.\n");
    } else {
        printf("Phone directory is full. Cannot add more contacts.\n");
    }
}

void search_contact(struct PhoneDirectory *directory, char *name) {
    int i, found = 0;
    for (i = 0; i < directory->count; i++) {
        if (strcmp(directory->contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", directory->contacts[i].name, directory->contacts[i].number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void display_contacts(struct PhoneDirectory *directory) {
    int i;
    printf("Contacts in the phone directory:\n");
    for (i = 0; i < directory->count; i++) {
        printf("%s - %s\n", directory->contacts[i].name, directory->contacts[i].number);
    }
}

int main() {
    struct PhoneDirectory directory;
    directory.count = 0;

    add_contact(&directory, "John", "1234567890");
    add_contact(&directory, "Alice", "9876543210");

    search_contact(&directory, "John");
    search_contact(&directory, "Bob");

    display_contacts(&directory);

    return 0;
}
