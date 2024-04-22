#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to hold book details
struct Book {
    char title[100];
    char author[100];
    char ISBN[20];
    int available; // 1 for available, 0 for issued
};

// Global array to store books
struct Book library[MAX_BOOKS];
int num_books = 0;

// Function to add a new book to the library
void add_book(const char *title, const char *author, const char *ISBN, int available) {
    if (num_books < MAX_BOOKS) {
        strcpy(library[num_books].title, title);
        strcpy(library[num_books].author, author);
        strcpy(library[num_books].ISBN, ISBN);
        library[num_books].available = available;
        num_books++;
        printf("Book added successfully.\n");
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

// Function to delete a book from the library (if available)
void delete_book(const char *title) {
    int i;
    for (i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (library[i].available == 1) {
                // Shift books after deleted book to fill the gap
                for (int j = i; j < num_books - 1; j++) {
                    library[j] = library[j + 1];
                }
                num_books--;
                printf("Book '%s' deleted successfully.\n", title);
                return;
            } else {
                printf("Book '%s' is currently issued. Cannot delete.\n", title);
                return;
            }
        }
    }
    printf("Book '%s' not found in the library.\n", title);
}

// Function to display details of a book
void display_book(const char *title) {
    int i;
    for (i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("ISBN: %s\n", library[i].ISBN);
            printf("Availability: %s\n", library[i].available ? "Available" : "Issued");
            return;
        }
    }
    printf("Book '%s' not found in the library.\n", title);
}

// Function to search for books by title or author
void search_books(const char *keyword) {
    int i, found = 0;
    printf("Search results:\n");
    for (i = 0; i < num_books; i++) {
        if (strstr(library[i].title, keyword) || strstr(library[i].author, keyword)) {
            printf("Title: %s, Author: %s, ISBN: %s, Availability: %s\n",
                    library[i].title, library[i].author, library[i].ISBN,
                    library[i].available ? "Available" : "Issued");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found matching the search criteria.\n");
    }
}

int main() {
    // Example usage:
    add_book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", 1);
    add_book("To Kill a Mockingbird", "Harper Lee", "9780061120084", 1);
    add_book("1984", "George Orwell", "9780451524935", 0);
    delete_book("The Great Gatsby");
    
    display_book("To Kill a Mockingbird");
    
    search_books("Harper Lee");
    
    return 0;
}

