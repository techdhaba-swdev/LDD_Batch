#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// Structure to represent a contact
typedef struct {
    char name[50];
    char phone_number[20];
} Contact;

// Function prototypes
void addContact(Contact**, int*);
void searchContact(Contact*, int);
void displayContacts(Contact*, int);
void deleteContact(Contact**, int*);
void updateContact(Contact*, int);

int main() {
    Contact* phoneBook = NULL;
    int numContacts = 0;
    int choice;

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. Update Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&phoneBook, &numContacts);
                break;
            case 2:
                searchContact(phoneBook, numContacts);
                break;
            case 3:
                displayContacts(phoneBook, numContacts);
                break;
            case 4:
                deleteContact(&phoneBook, &numContacts);
                break;
            case 5:
                updateContact(phoneBook, numContacts);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    // Free dynamically allocated memory
    free(phoneBook);

    return 0;
}

// Function to add a contact to the phone book
void addContact(Contact** phoneBook, int* numContacts) {
    *phoneBook = (Contact*)realloc(*phoneBook, (*numContacts + 1) * sizeof(Contact));
    if (*phoneBook == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", (*phoneBook)[*numContacts].name);
    printf("Enter phone number: ");
    scanf("%s", (*phoneBook)[*numContacts].phone_number);

    (*numContacts)++;
    printf("Contact added successfully.\n");
}

// Function to search for a contact in the phone book
void searchContact(Contact* phoneBook, int numContacts) {
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Name: %s, Phone Number: %s\n", phoneBook[i].name, phoneBook[i].phone_number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to display all contacts in the phone book
void displayContacts(Contact* phoneBook, int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Contacts in the phone book:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s, Phone Number: %s\n", phoneBook[i].name, phoneBook[i].phone_number);
    }
}

// Function to delete a contact from the phone book
void deleteContact(Contact** phoneBook, int* numContacts) {
    if (*numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char deleteName[50];
    printf("Enter name to delete: ");
    scanf("%s", deleteName);

    int found = 0;
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp((*phoneBook)[i].name, deleteName) == 0) {
            for (int j = i; j < *numContacts - 1; j++) {
                (*phoneBook)[j] = (*phoneBook)[j + 1];
            }
            *phoneBook = (Contact*)realloc(*phoneBook, (*numContacts - 1) * sizeof(Contact));
            if (*phoneBook == NULL && *numContacts - 1 > 0) {
                printf("Memory reallocation failed.\n");
                return;
            }
            (*numContacts)--;
            printf("Contact deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to update a contact in the phone book
void updateContact(Contact* phoneBook, int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char updateName[50];
    printf("Enter name to update: ");
    scanf("%s", updateName);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, updateName) == 0) {
            printf("Enter new name: ");
            scanf("%s", phoneBook[i].name);
            printf("Enter new phone number: ");
            scanf("%s", phoneBook[i].phone_number);
            printf("Contact updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}




