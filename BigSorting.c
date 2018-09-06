#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int strlength(char *str) {
  int i = 0;
  //printf("%s", str);
  while(str[i] != '\0') {
    i++;
  }
  return i;
}

// compares two strings and returns 1 if the first string has higher value, else 0
int compare(char *str1, char *str2, int len1, int len2) {
  //printf("%s\n", str1);
  // int len1 = strlength(str1);
  // int len2 = strlength(str2);
  //int len2 = 0;
  if (len1 > len2) {
    return 1;
  } else if (len1 < len2) {
    return 0;
  } else {
    int i = 0;
    while(i < len1 && str1[i] == str2[i]) {
      i++;
    }
    if (i < len1) {
      return str1[i] > str2[i];
    }
    return 1;
  }
}

void swap(char **str, int i, int j) {
  char* temp = str[i];
  str[i] = str[j];
  str[j] = temp;
}

void swapInt(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(char **arr, int low, int high, int *lengthArray) {
  char *pivot = arr[low];
  int i = low + 1, j = high;
  while(i <= j) {
    while(i <= high && compare(pivot, arr[i], lengthArray[low], lengthArray[i])) {
      i++;
    }
    while(j >= low && !compare(pivot, arr[j], lengthArray[low], lengthArray[j])) {
      j--;
    }
    if (i < j) {
      swap(arr, i ,j);
      swapInt(lengthArray, i, j);
    }
  }
  swap(arr, low, j);
  swapInt(lengthArray, low, j);
  return j;
}

void quickSort(char **arr, int low, int high, int *lengthArray) {
  if (low < high) {
    int pos = partition(arr, low, high, lengthArray);
    //printf("pos: %d\n", pos);
    quickSort(arr, low, pos-1, lengthArray);
    quickSort(arr, pos+1, high, lengthArray);
  }
}

int main(){

    int numberOfElements;
    scanf("%d", &numberOfElements);
    char **input;
    int lengthArray[numberOfElements];
    input = (char **)malloc(sizeof(char *) * numberOfElements);
    char temp[1000000];
    for(int i = 0; i < numberOfElements; i++) {
      scanf("%s", temp);
      lengthArray[i] = strlength(temp);
      input[i] = (char *)malloc(sizeof(char) * (lengthArray[i] + 1));
      memcpy(input[i], temp, (lengthArray[i] + 1)*sizeof(char));
      printf("%s\n", input[i]);
    }
    printf("\n===================\n");
    quickSort(input, 0, numberOfElements - 1, lengthArray);
    for(int i = 0; i < numberOfElements; i++) {
      // input[i] = (str)malloc(sizeOf(char) * 1000000);
      printf("%s\n", input[i]);
    }
    return 0;
}


