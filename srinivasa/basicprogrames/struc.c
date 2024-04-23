#include<stdio.h>
#include<string.h>
struct books
{
	char titel[50];
	char author[50];
	char subject[100];
	int book_id;
};
int main ()
{
	struct books book1;
	struct books book2;
	strcpy(book1.title,"c programing ");
	strcpy(book1.author,"nuha ali");
	strcpy(book1.subject,"c programing tutores");
	book1.book_id =6495407;
        strcpy(book1.title,"c programing ");
        strcpy(book1.author,"nuha ali");
        strcpy(book1.subject,"c programing tutores");
        book2.book_id =6495407;

