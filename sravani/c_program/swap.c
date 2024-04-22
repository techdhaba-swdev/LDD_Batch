#include<stdio.h>
void swap(int *ptr1, int *ptr2){
	int temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}
int main()
{
	int num1 =5,num2=10;
	printf("before swap %d %d\n",num1,num2);
	swap(&num1,&num2);
printf("after swap%d%d\n",num1,num2);

}



