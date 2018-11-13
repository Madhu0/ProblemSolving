#include<stdio.h>
#include<stdlib.h>
#include"../libutils.h"

int binarySearch(int *arr, int key, int low, int high, int direction, int *result) {
  if (low > high) {
    if (direction == 0) {
      return -1;
    } else {
      return 1;
    }
  }

  int mid = (low + high) / 2;
  // printf("%d %d %d\n", low, mid, high);
  if (arr[mid] == key) {
    switch(direction) {
      case -1:
        result[0] = mid;
        binarySearch(arr, key, low, mid - 1, direction, result);
        return 1;

      case 1:
        result[1] = mid;
        binarySearch(arr, key, mid + 1, high, direction, result);
        return 1;
      
      default:
        result[0] = mid;
        result[1] = mid;
        binarySearch(arr, key, low, mid, -1, result);
        binarySearch(arr, key, mid, high, 1, result);
        return 1;
    }
  } else if (arr[mid] > key) {
    return binarySearch(arr, key, low, mid - 1, direction, result);
  } else {
    return binarySearch(arr, key, mid + 1, high, direction, result);
  }
}

int main() {
  int len, key;
  scanf("%d", &len);
  int *arr = scanArray(len);
  // printArray(arr, len);
  scanf("%d", &key);
  int result[2];
  int tp = binarySearch(arr, key, 0, len - 1, 0, result);
  if (tp == -1) {
    printf("key not found");
    return 0;
  }
  printArray(result, 2);
  return 0;
}