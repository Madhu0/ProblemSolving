#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int binarySearch(int *arr, int low, int high, int key) {
  if (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (key < arr[mid]) {
      return binarySearch(arr, low, mid - 1, key);
    }
    return binarySearch(arr, mid + 1, high, key);
  }
  return -1;
}

int main() {
  int key, size;
  scanf("%d%d", &key, &size);
  int arr[size];
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  printf("%d\n", binarySearch(arr, 0, size - 1, key));
  return 0;
}