#include"main.h"

void main()
{
stack_init();

push(10);
push(12);
push(2);
push(20);


printf("\n1st pop = %d",pop());
printf("\n2st pop = %d",pop());
printf("\n3st pop = %d",pop());

printf("\nis stack empty %d",isStackEmpty());

printf("\nis stack full%d",isStackFull());

}
