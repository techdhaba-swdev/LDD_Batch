// Binary Search in C

#include <stdio.h>

int binarysearch(int array[], int l, int x, int r){
  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      l = mid + 1;

    else
      r = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(array) / sizeof(array[0]);
  int x = 8;
  int result = binarysearch(array, 0, x, n-1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}
