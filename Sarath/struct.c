#include <stdio.h>
#include <string.h>
struct books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};
int main()
{
	struct books book1;
	struct books book2;
	strcpy( book1.title,"c programming");
	strcpy( book1.author,"NUha ali");
	strcpy( book1.subject,"c programming tutorial");
	book1.book_id=657832;
	strcpy(book2.title,"telecom billing");
	strcpy(book2.author,"zara ali");
	strcpy(book2.subject,"telecom billing tutorial");
	book2.book_id=6876545;
	printf("Book 1 title: %s\n",book1.title);
	printf("Book 1 author : %s\n",book1.author);
	printf("Book 1 subject :%s\n",book1.subject);
	printf("Book 1 book_id: %d\n",book1.book_id);
	printf("Book 2 title: %s\n",book2.title);
        printf("Book 2 author : %s\n",book2.author);
        printf("Book 2 subject :%s\n",book2.subject);
        printf("Book 2 book_id: %d\n",book2.book_id);
}


