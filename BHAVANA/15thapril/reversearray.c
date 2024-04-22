#include <stdio.h>

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);


  for (int i = 0; i < n / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
