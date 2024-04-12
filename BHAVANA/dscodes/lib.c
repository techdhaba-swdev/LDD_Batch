#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_ISBN_LENGTH 20

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char ISBN[MAX_ISBN_LENGTH];
    int available;
};

struct Book library[MAX_BOOKS];
int numBooks = 0;

void addBook() {
    if (numBooks < MAX_BOOKS) {
        struct Book newBook;
        printf("Enter book title: ");
        scanf(" %[^\n]", newBook.title);
        printf("Enter author name: ");
        scanf(" %[^\n]", newBook.author);
        printf("Enter ISBN: ");
        scanf(" %[^\n]", newBook.ISBN);
        newBook.available = 1;
        library[numBooks++] = newBook;
        printf("Book added successfully.\n");
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

void deleteBook() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to delete: ");
    scanf(" %[^\n]", title);

    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, title) == 0 && library[i].available == 1) {
            for (int j = i; j < numBooks - 1; j++) {
                library[j] = library[j + 1];
            }
            numBooks--;
            found = 1;
            printf("Book '%s' deleted successfully.\n", title);
            break;
        }
    }
    if (!found)
        printf("Book not found or is not available.\n");
}

void displayBooks() {
    printf("\nBook Library:\n");
    printf("Title\t\tAuthor\t\tISBN\t\tAvailability\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%-15s %-15s %-15s %s\n", library[i].title, library[i].author, library[i].ISBN, (library[i].available ? "Available" : "Issued"));
    }
}

void searchByTitle() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title to search: ");
    scanf(" %[^\n]", title);

    int found = 0;
    printf("\nSearch Results:\n");
    printf("Title\t\tAuthor\t\tISBN\t\tAvailability\n");
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("%-15s %-15s %-15s %s\n", library[i].title, library[i].author, library[i].ISBN, (library[i].available ? "Available" : "Issued"));
            found = 1;
        }
    }
    if (!found)
        printf("Book not found.\n");
}

void searchByAuthor() {
    char author[MAX_AUTHOR_LENGTH];
    printf("Enter the author to search: ");
    scanf(" %[^\n]", author);

    int found = 0;
    printf("\nSearch Results:\n");
    printf("Title\t\tAuthor\t\tISBN\t\tAvailability\n");
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].author, author) == 0) {
            printf("%-15s %-15s %-15s %s\n", library[i].title, library[i].author, library[i].ISBN, (library[i].available ? "Available" : "Issued"));
            found = 1;
        }
    }
    if (!found)
        printf("No books found by this author.\n");
}

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Display Books\n");
        printf("4. Search By Title\n");
        printf("5. Search By Author\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                deleteBook();
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                searchByTitle();
                break;
            case 5:
                searchByAuthor();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
