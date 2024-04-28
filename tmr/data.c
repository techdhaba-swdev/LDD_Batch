#include<stdio.h>
typedef struct
{
	int arr[MAX];
	int max;
	int size;
}
LIST;
void insert (int j, int it,LIST *pl)
{
	int i;
	for (i=p1->size; i>=j; i=i--)
	{
		p1->arr[i+1]=p1->arr[i];
	}
	p1->arr[j]=it;
	p1->size++;


}
int main()
{
	LIST list;
	list.max=MAX;
	list.size=0;
	for (int i = 1;i<=3;i++)
	{
		printf("Enter a element%d: ",i);
		scanf("%d",list.arr[i]);
		list.size++;
	}
	int new_number:
		printf("Enter the number to insert")


