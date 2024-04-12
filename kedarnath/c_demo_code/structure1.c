#include<stdio.h>
#include<string.h>
struct Book{
	char title[100];
	char author[100];
	char subject[100];
	int book_id;
};

int main(){

	struct Book book1;
	strcpy(book1.title,"C Programming");
	strcpy(book1.author,"Dannis Riche");
	strcpy(book1.subject,"C");
	book1.book_id=1;

	struct Book book2;
        strcpy(book2.title,"Python");
        strcpy(book2.author,"V M Rao");
        strcpy(book2.subject,"Python");
        book2.book_id=2;


	printf("title is %s\n",book1.title);
	printf("author is %s\n",book1.author);
	printf("subject is %s\n",book1.subject);
	printf("book id is %d\n",book1.book_id);

	printf("title is %s\n",book2.title);
        printf("author is %s\n",book2.author);
        printf("subject is %s\n",book2.subject);
        printf("book id is %d\n",book2.book_id);

	return 0;


}
