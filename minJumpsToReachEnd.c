/*
Author: Madhusudhan Reddy K
Problem: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
TimeComplexity: O(n)
*/
#include <stdio.h>
#include <stdlib.h>
#include "libutils.h"

int findTheMaxSteps(int *arr, int len) {
  int maxReach = arr[0], localMax = arr[0], steps = 1, i;
  for(i = 1; i < len; i++) {
    if (i > maxReach)
      return -1;
    if (maxReach >= len) {
      return steps;
    } else if (i == maxReach) {
      if (i + arr[i] > localMax) {
        localMax = i + arr[i];
      }
      maxReach = localMax;
      steps++;
      if (maxReach >= len - 1)
        return steps;
    } else if (i + arr[i] > localMax) {
      localMax = i + arr[i];
    }
  }
  return -1;
}

int main() {
  int testcases;
  scanf("%d", &testcases);
  while(testcases--) {
    int len;
    scanf("%d", &len);
    int *arr = scanArray(len);
    printf("%d\n", findTheMaxSteps(arr, len));
    free(arr);
  }
  return 1;
}