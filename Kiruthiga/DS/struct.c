#include <stdio.h>
#include <string.h>
struct Books
{
char title[50];
chat author[50];
char subject[100];
int book_id;
};
int main()
{
struct Books Book1;
struct Books Book2;
strcpy (Book1.ttitle,"C programming");
strcpy (BooK1.author,"Nuha ali");
strcpy (Book1.subject,"C programming Tutorial");
strcpy (Book2.ttitle,"Telecom billing");
strcpy (Book2.author,"zara ali");
strcpy (Book2.subject,"Telecom billing tutorial");
printf("Book 1 title":%s\n", Book1.title);
printf("Book 1 Author":%s\n", Book1.Author);
printf("Book 1 subject:%s\n", Book1.subject);
printf("Book 1 book_id":%s\n", Book1.book_id);
printf("Book 2 title":%s\n",  Book2.title);
printf("Book 2 Author":%s\n", Book2.Author);
printf("Book 2 subject:%s\n", Book2.subject);
printf("Book 2 book_id":%s\n",Book2.book_id);
return 0;
}
