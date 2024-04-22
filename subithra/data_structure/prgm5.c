#include<stdio.h>
#include<string.h>
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
	strcpy(Book1.title," C Programming");
	strcpy(Book1.author," Nuha Ali");
	strcpy(Book1.subject,"Cprogramming tutorial");
	Book1.book_id=64958;

	strcpy(Book2.title,"telecom billing");
	strcpy(Book2.author,"Zara Ali");
	strcpy(Book2.subject,"TElecom billing");
	Book2.book_id=23456;
	printf("subject of book 2 is %s",Book2.subject);
}


