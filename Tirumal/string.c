#include <stdio.h>
#include <string.h>
struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};

int main()
{
	struct Books Book1;
	struct Books Book2;
	strcpy( Book1.title, "C programming");
	strcpy( Book1.author," Nuha Ali");
	strcpy(Book1.subject, " C programing Tutorial");
	Boo1.book_id = 6495407;
        strcpy( Book2.title, "Telecom Billing");
        strcpy( Book2.author," Zara  Ali");
        strcpy(Book2.subject, " Telecom Billing Tutorial");
        Book2.book_id  = 6495700; 
		

}
