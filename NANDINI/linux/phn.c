#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[15];
} Contact;

void addContact(Contact directory[], int *size) {
    if (*size >= MAX_CONTACTS) {
        printf("Directory is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", directory[*size].name);
    printf("Enter phone: ");
    scanf("%s", directory[*size].phone);
    (*size)++;
}

void searchContact(Contact directory[], int size) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < size; i++) {
        if (strcmp(directory[i].name, name) == 0) {
            printf("Found: %s - %s\n", directory[i].name, directory[i].phone);
            return;
        }
    }
    printf("Not found.\n");
}

void displayContacts(Contact directory[], int size) {
    if (size == 0) {
        printf("No contacts.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%s - %s\n", directory[i].name, directory[i].phone);
    }
}

int main() {
    Contact directory[MAX_CONTACTS];
    int size = 0, choice;
    while (1) {
        printf("\n1. Add\n2. Search\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) addContact(directory, &size);
        else if (choice == 2) searchContact(directory, size);
        else if (choice == 3) displayContacts(directory, size);
        else if (choice == 4) break;
        else printf("Invalid choice!\n");
    }
    return 0;
}
