#include <stdio.h>
#include <string.h>

struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};
int main ()
{
	struct Books Book1;
	struct Books Book2;

	strcpy( Book1.title, "C Programming");
	strcpy( Book1.author, "nuha Ali");
	strcpy( Book1.subject, "C Programming tutorial");
	Book1.book_id = 6495407;

	strcpy( Book2.title, "Telecom Billing");
	strcpy( Book2.author, "Zara Ali");
	strcpy( Book2.subject, "Telecom Billing Tutorial");
	Book2.book_id=6495700;

	printf( "book 1 title : %d\n", Book1.title);
	printf( "book 1 author : %s\n", Book1.author);
	printf( "book 1 subject: %s\n", Book1.subject);
        printf( "book 1 book_id: %s\n", Book1.book_id);

	printf( "book 1 title : %d\n", Book2.title);
        printf( "book 1 author : %s\n", Book2.author);
        printf( "book 1 subject : %s\n", Book2.subject);
        printf( "book 1 book_id : %s\n", Book2.book_id);
}
