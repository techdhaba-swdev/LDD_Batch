#include<stdio.h>

#define min (x,y)((x) < (y) ? (x):(y))

int jumpsearch(int arr[], int n, int k){
	int t=0;
	int b=(int)sqrt(n);


	while (a[min(b,n) - 1] < k) {
		t = b;
		b = b+(int)sqrt(n);
		if (t >= n)
			Jreturn -1;
	}

	while (a[t] < k) {
		t = t+1;
		if(t==min(b,n))
			return -1;
		if(a[t] == k)
			return t;
	}

	return -1;
}


int main()
{
	int a[7] = {1,3,2,4,5,6,7};
	int k =14;
	printf("Element Found at the position: %d/n", jumpsearch(a,7,k));
	return 0;
}
		


//Linear search, Binary search, Jumpsearch:
//
//Linear search: compare from one number to another from the beginning of the list until you find the desired number or reach the end of the list.

//Binary search: start from the middle of the phonebook. if the number you are looking for is before the middle number discard the second half of the list and focus on the first half and vice versa.

