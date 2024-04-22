#include <stdio.h>

#define SWAP(a, b){ \
		typeof(a) tmp=(a);\
		(a)=(b);\
		(b)=tmp;\
	}

int main() {
	int x=10,y=20;

	printf("Before Swap : x=%d,y=%d\n",x,y);
        SWAP(x,y);
	printf("After swap : x=%d,y=%d\n",x,y);

	return 0;
}
