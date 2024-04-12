#include <stdio.h>

int main() {
	int arr[5];
	int i,num,index;
	for(i=0;i<3;i++) {
		printf("enter element %d ",i+1);
		scanf("%d",&arr[i]);
	}
	 printf("before insertion");
                        for(i=0;i<5;i++)
                        {
                                printf("%d",arr[i]);
                        }

	printf("enter the new  number to insert ");
	scanf("%d",&num);
	printf("enter the index to insert ");
	scanf("%d",&index);

	if(index<0 ||index>=5){
		printf("Invalid index");}
		else{
			for(i=4;i>index;i--){
				arr[i]=arr[i-1];
			}
			arr[index]=num;

	printf("after insertion");
	    for(i=0;i<5;i++)
		{
		  printf("%d",arr[i]);
		}
	}
    return 0;
}
