#include <stdio.h>
#include <string.h>
#include <time.h>

struct books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

void displayBook(struct books book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Subject: %s\n", book.subject);
    printf("Book ID: %d\n", book.book_id);
    printf("\n");
}

int main() {
   clock_t start = clock();
    struct books book1;
    struct books book2;

    // Assigning values to book1
    strcpy(book1.title, "C Programming");
    strcpy(book1.author, "H&M");
    strcpy(book1.subject, "C Programming Tutorial");
    book1.book_id = 1234;

    // Assigning values to book2
    strcpy(book2.title, "Java Programming");
    strcpy(book2.author, "Zara");
    strcpy(book2.subject, "Java Programming Tutorial");
    book2.book_id = 12345;

    // Displaying book1 and book2
    clock_t end = clock();
    double time_taken= ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Details of Book 1:\n");
    displayBook(book1);

    printf("Details of Book 2:\n");
    displayBook(book2);
printf("time taken:%f seconds\n", time_taken);


    return 0;
}
