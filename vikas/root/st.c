#include<stdio.h>
#include<string.h>
struct Books
{
	char title[50];
	char author[50];
	char subject[50];
	int id;
};
void main( )
{
	struct Books book1;
	struct Books book2;
	strcpy(book1.title,"c programming");
	strcpy(book1.author,"Nuha ali");
	strcpy(book1.subject,"c tutorial");
	book1.id=54326;
        strcpy(book2.title,"c++ programming");
        strcpy(book2.author,"Eara ali");
        strcpy(book2.subject,"c++ tutorial");
        book2.id=54326;
	printf("title:%s\nauthor:%s\nsubject:%s\nid:%d\n",book1.title,book1.author,book1.subject,        book1.id);
        printf("title:%s\nauthor:%s\nsubject:%s\nid:%d\n",book2.title,book2.author,book2.subject,        book2.id);
}
 
