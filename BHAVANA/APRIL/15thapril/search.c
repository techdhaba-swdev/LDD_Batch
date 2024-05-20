#include <stdio.h>

int linearSearch(int *arr, int size, int key) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9};
  int key = 5;

  int index = linearSearch(arr, sizeof(arr) / sizeof(arr[0]), key);

  if (index == -1) {
    printf("Element not found.\n");
  } else {
    printf("Element found at index %d.\n", index);
  }

  return 0;
}
