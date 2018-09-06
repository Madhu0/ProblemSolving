/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */
#include<stdio.h>
int ISINRANGE(int x, int a, int b){
    return ((a <= x) && (x < b));
}

int ABS(int a, int b) {
    if (a - b < 0) {
        return (a - b) * -1;
    }
    return a - b;
}

int findMax(int *arr, int start, int end) {
    int i, max = arr[start], maxPos = start;
    for (i = start + 1;i < end;i++) {
        if (max < arr[i]) {
            max = arr[i];
            maxPos = i;
        }
    }
    return maxPos;
}

int findMin(int *arr, int start, int end) {
    int i, min = arr[start], minPos = start;
    for (i = start + 1;i < end;i++) {
        if (min > arr[i]) {
            min = arr[i];
            minPos = i;
        }
    }
    return minPos;
}

int findMaxInGivenSubArray(int pos1, int pos2, int start, int end, int *array) {
    if (!ISINRANGE(pos1, start, end) || !ISINRANGE(pos2, start, end)) {
        return 0;
    }
    int currentMax = ABS(pos1, pos2) + ABS(array[pos1], array[pos2]);
    if ((pos1 == start && pos2 + 1 == end) || (pos2 == start && pos1 + 1 == end)) {
        return currentMax;
    }
    int tempPos2 = pos2 + 1;
    // printf("%d %d %d ", pos1, pos2, currentMax);
    if (!ISINRANGE(pos2 + 1, start, end)) {
        tempPos2 = pos2;
    }
    int maxPos, minPos, tempMax;
    maxPos = findMax(array, start, pos1);
    minPos = findMin(array, tempPos2, end);
    tempMax = findMaxInGivenSubArray(maxPos, minPos, start, end, array);
    if (currentMax < tempMax) {
        currentMax = tempMax;
    }
    minPos = findMin(array, start, pos1);
    maxPos = findMax(array, tempPos2, end);
    tempMax = findMaxInGivenSubArray(minPos, maxPos, start, end, array);
    if (currentMax < tempMax) {
        currentMax = tempMax;
    }
    // printf("%d %d %d ", pos1, pos2, currentMax);
    return currentMax;
}

int maxArr(int* A, int n1) {
    int maxPos, minPos;
    maxPos = findMax(A, 0, n1);
    minPos = findMin(A, 0, n1);
    if (maxPos == minPos) {
        return n1 - 1;
    }
    if (maxPos < minPos) {
        return findMaxInGivenSubArray(maxPos, minPos, 0, n1, A);
    }
    return findMaxInGivenSubArray(minPos, maxPos, 0, n1, A);
}

int main() {
    int size;
    scanf("%d", &size);
    int arr[size], i;
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", maxArr(arr, size));
    return 0;
}
