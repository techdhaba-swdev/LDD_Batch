#include<stdio.h>
void main()
{
	int a[10],i,j,swap,n;
	printf("enter array size:");
	scanf("%d",&n);
	printf("enter array elements:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				swap=a[i];
				a[i]=a[j];
				a[j]=swap;
			}
		}
	}
	printf("after swapping thw array elements are:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

