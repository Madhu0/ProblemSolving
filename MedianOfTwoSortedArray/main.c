#include <stdio.h>

int getMedian(int *arr, int low, int high) {
    int len = high - low + 1;
    int mid = (int)len / 2;
    if (len % 2 == 0) {
        return (arr[low + mid - 1] + arr[low + mid]) / 2;
    }
    return arr[low + mid];
}

int findMedianOfTwoSortedArrays(int *arr1, int start1, int end1, int *arr2, int start2, int end2) {
    int m1 = getMedian(arr1, start1, end1);
}

int main() {


}
