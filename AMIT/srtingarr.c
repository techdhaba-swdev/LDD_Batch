#include<stdio.h>
#include<string.h>
struct books
{
	char title[50];
	char author[50];
	char sub[50];
	int book_id;
};
int main()
{
	struct books book1;
	struct books book2;

	strcpy(book1.title,"C-Programming");
	strcpy(book1.author,"Nuha Ali");
	strcpy(book1.sub,"C programming tutorial");
	book1.book_id=6495407;

	strcpy(book2.title,"Telecom Billing");
        strcpy(book2.author,"Zara Ali");
        strcpy(book2.sub,"Telecom Billing  tutorial");
        book1.book_id=6495700;

	printf("book 1 title:%s\n",book1.title);
	 printf("book 1 title:%s\n",book1.author);	 
         printf("book 1 title:%s\n",book1.sub);
	 printf("book 1 title:%d\n",book1.book_id);

       printf("book 2 title:%s\n",book2.title);
         printf("book 2 title:%s\n",book2.author);
         printf("book 2 title:%s\n",book2.sub);
         printf("book 2 title:%d\n",book2.book_id);

	 return 0;
}
	 
