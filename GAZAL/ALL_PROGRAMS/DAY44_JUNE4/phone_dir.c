#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

Contact phoneDirectory[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        printf("Enter name: ");
        scanf("%s", phoneDirectory[contactCount].name);
        printf("Enter phone number: ");
        scanf("%s", phoneDirectory[contactCount].phone);
        contactCount++;
        printf("Contact added successfully.\n");
    } else {
        printf("Phone directory is full.\n");
    }
}

void searchContact() {
    char searchName[NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneDirectory[i].name, searchName) == 0) {
            printf("Contact found: %s - %s\n", phoneDirectory[i].name, phoneDirectory[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts in the directory.\n");
    } else {
        printf("Phone Directory:\n");
        for (int i = 0; i < contactCount; i++) {
            printf("%s - %s\n", phoneDirectory[i].name, phoneDirectory[i].phone);
        }
    }
}

void showMenu() {
    printf("\nPhone Directory Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Display Contacts\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}