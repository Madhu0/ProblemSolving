#include<stdio.h>

int findSquareRoot(int num) {
  int low = 1, high = num;
  while(low < high) {
    int mid = (low + high) / 2;
    int value = mid * mid;
    if (value == num) {
      return mid;
    } else if (value < num) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return low;
}

int main() {
  int num;
  scanf("%d", &num);
  printf("Approx Square root of %d is %d", num, findSquareRoot(num));
  return 0;
}